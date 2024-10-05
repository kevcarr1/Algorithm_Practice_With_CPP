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

    bool bubbleSortStatus = false;
    bool insertionSortStatus = false;
    bool selectionSortStatus = false;
    bool mergeSortStatus = false;

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
    bubbleSortStatus = checkIntsAscending(randArray1);
#if 0 
    checkStatus(bubbleSortStatus);
#endif

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
    insertionSortStatus = checkIntsAscending(randArray2);
#if 0
    checkStatus(insertionSortStatus);
#endif

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
    selectionSortStatus = checkIntsAscending(randArray3);
#if 0 
    checkStatus(selectionSortStatus);
#endif

    // MERGE SORT
    vector<int> randArray4 = randArray;
    cout << "Merge Sort:" << endl;
    printUnsortedArray(randArray4);
    start = high_resolution_clock::now();
    mergeSort(randArray4, 0, randArray4.size() - 1);
    stop = high_resolution_clock::now();
    printSortedArray(randArray4);
    auto mergeTime = duration_cast<microseconds>(stop - start);
    cout << "Time to complete: " << mergeTime.count() << " microseconds" << endl;
    mergeSortStatus = checkIntsAscending(randArray4);

    cout << endl;

    cout << "     Benchmark Summary:     " << endl;
    cout << "============================" << endl;
    cout << "Bubble Sort Time: " << bubbleTime.count() << " microseconds ";
    checkStatus(bubbleSortStatus);
    cout << "Insertion Sort Time: " << insertionTime.count() << " microseconds ";
    checkStatus(insertionSortStatus);
    cout << "Selection Sort Time: " << selectionTime.count() << " microseconds ";
    checkStatus(selectionSortStatus);
    cout << "Merge Sort Time: " << mergeTime.count() << " microseconds ";
    checkStatus(mergeSortStatus);

    cout << endl;

    cout << "    Practice Algorithms    " << endl;
    cout << "===========================" << endl;

    // PRACTICE

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