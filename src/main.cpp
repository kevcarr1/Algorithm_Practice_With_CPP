#include <iostream>
#include <chrono>
#include "TestData/TestData.h"
#include "Benchmarking/Benchmark.h"
#include "SortingAlgorithms/Sorting.h"
#include "Practice/practice.h"

using namespace std;
using namespace std::chrono;

void PracticeCheckStatus(bool testResult, int time);
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

    Benchmark BubbleSortObj(bubbleSort, randArray);
    Benchmark InsertionSortObj(insertionSort, randArray);
    Benchmark SelectionSortObj(selectionSort, randArray);
    Benchmark MergeSortObj(mergeSort, randArray);
    Benchmark QuickSortObj(quickSort, randArray);
    Benchmark HeapSortObj(heapSort, randArray);
    Benchmark TimSortObj(timSort, randArray);

    cout << "     Benchmark Summary:     " << endl;
    cout << "============================" << endl;
    cout << "Bubble Sort Time: " << BubbleSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(BubbleSortObj.isAscending());
    cout << "Insertion Sort Time: " << InsertionSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(InsertionSortObj.isAscending());
    cout << "Selection Sort Time: " << SelectionSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(SelectionSortObj.isAscending());
    cout << "Merge Sort Time: " << MergeSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(MergeSortObj.isAscending());
    cout << "Quick Sort Time: " << QuickSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(QuickSortObj.isAscending());
    cout << "Heap Sort Time: " << HeapSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(HeapSortObj.isAscending());
    cout << "Tim Sort Time: " << TimSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(TimSortObj.isAscending());

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

    // PRACTICE
    cout << "    PRACTICE RESULTS    " << endl;
    cout << "========================" << endl;

    cout << "Practice Bubble Sort: ";
    Benchmark PracticeBubbleSortObj(practiceBubbleSort, randArray);
    int pBubTime = PracticeBubbleSortObj.getTimeToCalcMs();
    cout << pBubTime << " microseconds ";
    bool prBubTest = PracticeBubbleSortObj.isAscending();
    PracticeCheckStatus(prBubTest, pBubTime);

    cout << "Practice Selection Sort: ";
    Benchmark PracticeSelectionSortObj(practiceSelectionSort, randArray);
    int pSelTime = PracticeSelectionSortObj.getTimeToCalcMs();
    cout << pSelTime << " microseconds ";
    bool prSelTest = PracticeSelectionSortObj.isAscending();
    PracticeCheckStatus(prSelTest, pSelTime);

    cout << "Practice Insertion Sort: ";
    Benchmark InsertionSortTestObj(practiceInsertionSort, randArray);
    int pInsertTime = InsertionSortTestObj.getTimeToCalcMs();
    cout << pInsertTime << " microseconds ";
    bool prInsertTest = InsertionSortTestObj.isAscending();
    PracticeCheckStatus(prInsertTest, pInsertTime);

    cout << "Practice Merge Sort: ";
    Benchmark MergeSortTestObj(practiceMergeSort, randArray);
    int pMergeTime = MergeSortTestObj.getTimeToCalcMs();
    cout << pMergeTime << " microseconds ";
    auto prMergeStatus = MergeSortTestObj.isAscending();
    PracticeCheckStatus(prMergeStatus, pMergeTime);

    cout << "Practice Quick Sort: ";
    Benchmark PracticeQuickSortObj(practiceQuickSort, randArray);
    int pQuickTime = PracticeQuickSortObj.getTimeToCalcMs();
    cout << pQuickTime << " microseconds ";
    auto pQuickSortStatus = PracticeQuickSortObj.isAscending();
    PracticeCheckStatus(pQuickSortStatus, pQuickTime);

    cout << "Practice Heap Sort: ";
    Benchmark HeapSortTestObj(practiceHeapSort, randArray);
    int pHeapTime = HeapSortTestObj.getTimeToCalcMs();
    cout << pHeapTime << " microseconds ";
    bool pHeapSortStatus = HeapSortTestObj.isAscending();
    PracticeCheckStatus(pHeapSortStatus, pHeapTime);

    cout << "Practice TimSort: ";
    Benchmark TimSortTestObj(practiceTimSort, randArray);
    int pTimSortTime = TimSortTestObj.getTimeToCalcMs();
    cout << pTimSortTime << " microseconds ";
    auto pTimSortStatus = TimSortTestObj.isAscending();
    PracticeCheckStatus(pTimSortStatus, pTimSortTime);

    return;
}

void PracticeCheckStatus(bool testResult, int time)
{
    if (testResult == false && time <= 1)
    {
        cout << "[NO IMPLEMENTATION]" << endl;
    }
    else
    {
        checkStatus(testResult);
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