#include "sorting.hpp"

void insertionSort(std::vector<int>& arr, int esq, int dir) {
    // Começa no segundo elemento do sub-array (esq + 1) e vai até dir - 1
    for (int i = esq + 1; i < dir; ++i) {
        int chave = arr[i];
        int j = i - 1;

        // Move os elementos do array (de esq até i-1) que são 
        // maiores que a chave para uma posição à frente
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