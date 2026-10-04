#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include "sorting.hpp"

int main() {
    // 1. Gera os tamanhos dinamicamente ( 100.000 a 500.000 com saltos de 100.000)
    std::vector<int> tamanhos;
    for (int i = 100000; i <= 500000; i += 100000) {
        tamanhos.push_back(i);
    }
    std::string pasta_atual = "test_data/melhor_caso/";
    
    const int TRIALS = 5;
    int num_exercicio = 1;
    
    struct Algoritmo {
        std::string nome;
        std::function<void(std::vector<int>&, int, int)> funcao;
    };

    std::vector<Algoritmo> algoritmos = {
        {"InsertionSort", insertionSort},
        {"SelectionSort", selectionSort},
        {"BubbleSort", bubbleSort},
        {"QuickSort", quickSort},
        {"MergeSort", mergeSort}
    };

    // Imprime o cabeçalho do ficheiro CSV
    std::cout << "Tamanho";
    for (const auto& algo : algoritmos) {
        std::cout << "," << algo.nome;
    }
    std::cout << "\n";

    for (int size : tamanhos) {
        std::string filename = pasta_atual + "p" + std::to_string(num_exercicio) + "v" + std::to_string(size) + ".txt";
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o ficheiro: " << filename << "\n";
            continue;
        }

        std::vector<int> dados_originais(size);
        for (int i = 0; i < size; ++i) {
            file >> dados_originais[i];
        }
        file.close();

        std::cout << size; 
        
        // Imprime o progresso no terminal para saber que o programa não bloqueou
        std::cerr << "A processar tamanho: " << size << "...\n";

        for (const auto& algo : algoritmos) {
            long long totalDuration = 0;

            for (int t = 0; t < TRIALS; ++t) {
                std::vector<int> vec = dados_originais; 
                auto start = std::chrono::high_resolution_clock::now();
                algo.funcao(vec, 0, vec.size());
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                totalDuration += duration;
            }

            long long averageDuration = totalDuration / TRIALS;
            std::cout << "," << averageDuration;
        }
        std::cout << "\n";
    }

    return 0;
}