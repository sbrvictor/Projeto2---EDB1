#include "sorting.hpp"
#include <algorithm> // Para usar std::swap

// 1. Insertion Sort
void insertionSort(std::vector<int>& arr, int esq, int dir) {
    // Começa no segundo elemento do sub-array (esq + 1) e vai até dir - 1
    for (int i = esq + 1; i < dir; ++i) {
        int chave = arr[i];
        int j = i - 1;

        // Move os elementos que são maiores que a chave uma posição para a direita
        while (j >= esq && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insere a chave na sua posição correta
        arr[j + 1] = chave;
    }
}

// 2. Selection Sort
void selectionSort(std::vector<int>& arr, int esq, int dir) {
    // Percorre o array desde o início (esq) até ao penúltimo elemento do intervalo
    for (int i = esq; i < dir - 1; ++i) {
        int min_idx = i;
        
        // Procura o menor elemento no restante do array não ordenado
        for (int j = i + 1; j < dir; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o elemento atual com o menor elemento encontrado
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

// 3. Bubble Sort
void bubbleSort(std::vector<int>& arr, int esq, int dir) {
    int n = dir - esq; // Número total de elementos a ordenar
    
    for (int i = 0; i < n - 1; ++i) {
        bool trocou = false;
        // Percorre o array e empurra o maior elemento para o fim da secção não ordenada
        for (int j = esq; j < dir - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                trocou = true;
            }
        }
        // Otimização: Se nenhuma troca ocorreu, o array já está ordenado
        if (!trocou) break;
    }
}

// --- Funções Auxiliares e Principais para Quick Sort ---

// Função auxiliar para particionar o array no Quick Sort
int partition(std::vector<int>& arr, int esq, int dir) {
    // --- OTIMIZAÇÃO PARA EVITAR STACK OVERFLOW ---
    // Escolhe o elemento central e coloca-o na última posição
    int meio = esq + (dir - esq) / 2;
    std::swap(arr[meio], arr[dir - 1]);
    // ---------------------------------------------

    int pivot = arr[dir - 1]; // Agora o pivô é um elemento mais equilibrado
    int i = esq - 1; // Índice do menor elemento

    // Coloca os elementos menores que o pivô à esquerda
    for (int j = esq; j < dir - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Coloca o pivô na sua posição final
    std::swap(arr[i + 1], arr[dir - 1]);
    return i + 1;
}

// 4. Quick Sort
void quickSort(std::vector<int>& arr, int esq, int dir) {
    // Condição de paragem: se o intervalo tiver mais de 1 elemento
    if (esq < dir - 1) {
        // pi é o índice de particionamento (o pivô está na posição correta)
        int pi = partition(arr, esq, dir);

        // Ordena recursivamente antes e depois da partição
        // Note a convenção [esq, dir): o pivô 'pi' fica de fora das chamadas
        quickSort(arr, esq, pi);
        quickSort(arr, pi + 1, dir);
    }
}

// --- Funções Auxiliares e Principais para Merge Sort ---

// Função auxiliar para intercalar (merge) duas metades ordenadas
void merge(std::vector<int>& arr, int esq, int meio, int dir) {
    int n1 = meio - esq;
    int n2 = dir - meio;

    // Vetores temporários para guardar as metades
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + j];

    int i = 0, j = 0, k = esq;
    
    // Intercala os dois vetores de volta no array original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes da metade esquerda, se existirem
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes da metade direita, se existirem
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 5. Merge Sort
void mergeSort(std::vector<int>& arr, int esq, int dir) {
    // Condição de paragem: se o intervalo tiver mais de 1 elemento
    if (dir - esq > 1) {
        int meio = esq + (dir - esq) / 2;

        // Ordena recursivamente a primeira e a segunda metade
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio, dir);

        // Une as metades ordenadas
        merge(arr, esq, meio, dir);
    }
}