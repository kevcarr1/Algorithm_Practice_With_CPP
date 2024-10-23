#include <iostream>
#include "Benchmark.h"
#include "../SortingAlgorithms/Sorting.h"
#include "../TestData/TestData.h"

using namespace std;

/************************************************************
 * @brief Benchmarks the sorting algorithms
 ***********************************************************/
void benchmarkingSortingAlgorithms(int length)
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