#ifndef SORTING_H
#define SORTING_H

#include <vector>

using namespace std;

/* Sorting arrays of integers */
void bubbleSort(vector<int> &arr);
void bubbleSortDesc(vector<int> &arr);
void insertionSort(vector<int> &arr);
void insertionSortDesc(vector<int> &arr);
void selectionSort(vector<int> &arr);
void SelectionSortDescending(vector<int> &arr);
void mergeSort(vector<int> &arr);
void quickSort(vector<int> &arr);
void heapSort(vector<int> &arr);
void timSort(vector<int> &arr);

/* Sorting arrays of Users */
void sortUsers(vector<User> &userList);

#endif