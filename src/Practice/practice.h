#ifndef PRACTICE_H
#define PRACTICE_H

#include <vector>
#include "../TestData/GenUsers.h"

using namespace std;

void practiceBubbleSort(vector<int> &arr);
void practiceSelectionSort(vector<int> &arr);
void practiceInsertionSort(vector<int> &arr);
void practiceMergeSort(vector<int> &arr);
void practiceQuickSort(vector<int> &arr);
void practiceHeapSort(vector<int> &arr);
void practiceTimSort(vector<int> &arr);

User findUser_LinearSearchPractice(vector<User> &userList, string name);
User findUser_HashMapPractice(vector<User> &userList, string name);

void practiceSortingAlgorithms(int length);
void practiceSearchingAlgorithms(int numUsers);

#endif