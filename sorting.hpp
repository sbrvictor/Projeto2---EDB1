#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

// Declarações das funções com a convenção [esq, dir)
void insertionSort(std::vector<int>& arr, int esq, int dir);
void selectionSort(std::vector<int>& arr, int esq, int dir);
void bubbleSort(std::vector<int>& arr, int esq, int dir);
void quickSort(std::vector<int>& arr, int esq, int dir);
void mergeSort(std::vector<int>& arr, int esq, int dir);

#endif