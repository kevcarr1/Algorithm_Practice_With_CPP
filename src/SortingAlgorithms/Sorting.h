#ifndef SORTING_H
#define SORTING_H

#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr);
void insertionSort(vector<int> &arr);
void selectionSort(vector<int> &arr);
void mergeSort(vector<int> &arr, int left, int right);
void quickSort(vector<int> &arr);
void heapSort(vector<int> &arr);

#endif