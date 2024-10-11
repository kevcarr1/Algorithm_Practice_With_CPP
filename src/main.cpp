#include <iostream>
#include <chrono>
#include "TestData/TestData.h"
#include "SortingAlgorithms/Sorting.h"
#include "Practice/practice.h"

using namespace std;
using namespace std::chrono;

void printSortedArray(vector<int> &arr);
void printUnsortedArray(vector<int> &arr);
void printArray(vector<int> &arr);
static void benchmarkingSortingAlgorithms(int length);
static void practiceSortingAlgorithms(int length);

int main()
{
    int length = 10;

    // Introduction
    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    cout << endl;
    cout << "How long of an array would you like: ";
    cin >> length;
    cout << endl;

    benchmarkingSortingAlgorithms(length);

    cout << endl;

    practiceSortingAlgorithms(length);

    return 0;
}

/************************************************************
 * @brief Benchmarks the sorting algorithms
 ***********************************************************/
static void benchmarkingSortingAlgorithms(int length)
{
    int min = 1;
    int max = 100;

    vector<int> randArray = generateRandomIntArray(length, min, max);
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    // BUBBLE SORT
    vector<int> randArray1 = randArray;
    start = high_resolution_clock::now();
    bubbleSort(randArray1);
    stop = high_resolution_clock::now();
    auto bubbleTime = duration_cast<microseconds>(stop - start);

    // INSERTION SORT
    vector<int> randArray2 = randArray;
    start = high_resolution_clock::now();
    insertionSort(randArray2);
    stop = high_resolution_clock::now();
    auto insertionTime = duration_cast<microseconds>(stop - start);

    // SELECTION SORT
    vector<int> randArray3 = randArray;
    start = high_resolution_clock::now();
    selectionSort(randArray3);
    stop = high_resolution_clock::now();
    auto selectionTime = duration_cast<microseconds>(stop - start);

    // MERGE SORT
    vector<int> randArray4 = randArray;
    start = high_resolution_clock::now();
    mergeSort(randArray4);
    stop = high_resolution_clock::now();
    auto mergeTime = duration_cast<microseconds>(stop - start);

    // QUICK SORT
    vector<int> randArray5 = randArray;
    start = high_resolution_clock::now();
    quickSort(randArray5);
    stop = high_resolution_clock::now();
    auto quickSortTime = duration_cast<microseconds>(stop - start);

    // HEAP SORT
    vector<int> randArray6 = randArray;
    start = high_resolution_clock::now();
    heapSort(randArray6);
    stop = high_resolution_clock::now();
    auto heapSortTime = duration_cast<microseconds>(stop - start);

    cout << "     Benchmark Summary:     " << endl;
    cout << "============================" << endl;
    cout << "Bubble Sort Time: " << bubbleTime.count() << " microseconds " << endl;
    cout << "Insertion Sort Time: " << insertionTime.count() << " microseconds " << endl;
    cout << "Selection Sort Time: " << selectionTime.count() << " microseconds " << endl;
    cout << "Merge Sort Time: " << mergeTime.count() << " microseconds " << endl;
    cout << "Quick Sort Time: " << quickSortTime.count() << " microseconds " << endl;
    cout << "Heap Sort Time: " << heapSortTime.count() << " microseconds " << endl;

    return;
}

/************************************************************
 * @brief Function groups practice function calls together
 ***********************************************************/
static void practiceSortingAlgorithms(int length)
{
    int min = 0;
    int max = 100;
    vector<int> randArray = generateRandomIntArray(length, min, max);
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    // PRACTICE
    cout << "    PRACTICE RESULTS    " << endl;
    cout << "========================" << endl;

    vector<int> randArrayA = randArray;
    cout << "Practice Bubble Sort: ";
    start = high_resolution_clock::now();
    // BUBBLE SORT PRACTICE
    practiceBubbleSort(randArrayA);
    stop = high_resolution_clock::now();
    auto bubTestTime = duration_cast<microseconds>(stop - start);
    cout << bubTestTime.count() << " microseconds ";
    bool prBubTest = checkIntsAscending(randArrayA);
    if (prBubTest == false && bubTestTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(prBubTest);
    }

    vector<int> randArrayB = randArray;
    cout << "Practice Selection Sort: ";
    start = high_resolution_clock::now();
    // SELECTION SORT PRACTICE
    practiceSelectionSort(randArrayB);
    stop = high_resolution_clock::now();
    auto selectSortTime = duration_cast<microseconds>(stop - start);
    cout << selectSortTime.count() << " microseconds ";
    bool prSelTest = checkIntsAscending(randArrayB);
    if (prSelTest == false && selectSortTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(prSelTest);
    }

    vector<int> randArrayC = randArray;
    cout << "Practice Insertion Sort: ";
    start = high_resolution_clock::now();
    // INSERTION SORT
    practiceInsertionSort(randArrayC);
    stop = high_resolution_clock::now();
    auto prInsTime = duration_cast<microseconds>(stop - start);
    cout << prInsTime.count() << " microseconds ";
    auto InsCor = checkIntsAscending(randArrayC);
    if (InsCor == false && prInsTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(InsCor);
    }

    vector<int> randArrayD = randArray;
    cout << "Practice Merge Sort: ";
    start = high_resolution_clock::now();
    // MERGE SORT
    practiceMergeSort(randArrayD);
    stop = high_resolution_clock::now();
    auto prMergeTime = duration_cast<microseconds>(stop - start);
    cout << prMergeTime.count() << " microseconds ";
    auto prMergeStatus = checkIntsAscending(randArrayD);
    if (prMergeStatus == false && prMergeTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(prMergeStatus);
    }

    vector<int> randArrayE = randArray;
    cout << "Practice Quick Sort: ";
    start = high_resolution_clock::now();
    // QUICK SORT
    practiceQuickSort(randArrayE);
    stop = high_resolution_clock::now();
    auto pQuickSortTime = duration_cast<microseconds>(stop - start);
    cout << pQuickSortTime.count() << " microseconds ";
    auto pQuickSortStatus = checkIntsAscending(randArrayE);
    if (pQuickSortStatus == false && pQuickSortTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(pQuickSortStatus);
    }

    vector<int> randArrayF = randArray;
    cout << "Practice Heap Sort: ";
    start = high_resolution_clock::now();
    // HEAP SORT
    practiceHeapSort(randArrayF);
    stop = high_resolution_clock::now();
    auto pHeapSortTime = duration_cast<microseconds>(stop - start);
    cout << pHeapSortTime.count() << " microseconds ";
    auto pHeapSortStatus = checkIntsAscending(randArrayF);
    if (pQuickSortStatus == false && pHeapSortTime.count() == 0)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(pHeapSortStatus);
    }

    return;
}

/************************************************************
 * @brief Prints the array with an unsorted heading
 ***********************************************************/
void printUnsortedArray(vector<int> &arr)
{
    cout << "Unsorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

/************************************************************
 * @brief Prints the array with a Sorted heading
 ***********************************************************/
void printSortedArray(vector<int> &arr)
{
    cout << "Sorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

/************************************************************
 * @brief Prints the array
 ***********************************************************/
void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (int i : arr)
        cout << i << " ";
    cout << "]";

    return;
}