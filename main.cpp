#include <iostream>
#include <vector>
#include <chrono>
#include "sorting.hpp"

int main() {
    // 1. Configurar o vetor de teste (pior caso com 10 elementos)
    std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "Vetor antes da ordenacao:\n";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 2. Iniciar a medição de tempo
    auto start = std::chrono::high_resolution_clock::now();

    // 3. Chamar a função (esq = 0, dir = 10)
    bubbleSort(vec, 0, vec.size());

    // 4. Parar a medição de tempo
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // 5. Mostrar resultados
    std::cout << "Vetor depois da ordenacao:\n";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    std::cout << "Tempo de execucao (tamanho " << vec.size() << "): " << duration << " ns\n";

    return 0;
}