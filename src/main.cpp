#include <iostream>
#include <chrono>
#include "TestData/TestData.h"
#include "SortingAlgorithms/Sorting.h"

using namespace std;
using namespace std::chrono;

void printSortedArray(vector<int> &arr);
void printUnsortedArray(vector<int> &arr);
void printArray(vector<int> &arr);

int main()
{
    int length = 10;

    // Introduction
    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    cout << endl;
    cout << "How long of an array would you like: ";
    cin >> length;
    cout << endl;

    int min = 1;
    int max = 100;

    vector<int> randArray = generateRandomIntArray(length, min, max);
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    // BUBBLE SORT
    vector<int> randArray1 = randArray;
    cout << "Here's an example of Bubble Sort on the following array:" << endl;

    printUnsortedArray(randArray1);
    start = high_resolution_clock::now();
    bubbleSort(randArray1);
    stop = high_resolution_clock::now();
    printSortedArray(randArray1);
    auto bubbleTime = duration_cast<microseconds>(stop - start);
    cout << "Time to complete: " << bubbleTime.count() << " microseconds" << endl;

    cout << endl;

    // INSERTION SORT
    vector<int> randArray2 = randArray;
    cout << "Here's an example of Insertion Sort to sort the same array:" << endl;

    printUnsortedArray(randArray2);
    start = high_resolution_clock::now();
    insertionSort(randArray2);
    stop = high_resolution_clock::now();
    printSortedArray(randArray2);
    auto insertionTime = duration_cast<microseconds>(stop - start);
    cout << "Time to complete: " << insertionTime.count() << " microseconds" << endl;

    cout << endl;

    // SELECTION SORT
    vector<int> randArray3 = randArray;
    cout << "Here's an example of Selection Sort to sort the same array:" << endl;

    printUnsortedArray(randArray3);
    start = high_resolution_clock::now();
    selectionSort(randArray3);
    stop = high_resolution_clock::now();
    printSortedArray(randArray3);
    auto selectionTime = duration_cast<microseconds>(stop - start);
    cout << "Time to complete: " << selectionTime.count() << " microseconds" << endl;

    cout << endl;

    cout << "Benchmark Summary:" << endl;
    cout << "Bubble Sort Time: " << bubbleTime.count() << " microseconds" << endl;
    cout << "Insertion Sort Time: " << insertionTime.count() << " microseconds" << endl;
    cout << "Selection Sort Time: " << selectionTime.count() << " microseconds" << endl;

    return 0;
}

void printUnsortedArray(vector<int> &arr)
{
    cout << "Unsorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

void printSortedArray(vector<int> &arr)
{
    cout << "Sorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (int i : arr)
        cout << i << " ";
    cout << "]";

    return;
}