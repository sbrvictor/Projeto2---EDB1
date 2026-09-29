#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

// Declaração da função com a convenção [esq, dir)
void insertionSort(std::vector<int>& arr, int esq, int dir);
void selectionSort(std::vector<int>& arr, int esq, int dir);
void bubbleSort(std::vector<int>& arr, int esq, int dir);

#endif