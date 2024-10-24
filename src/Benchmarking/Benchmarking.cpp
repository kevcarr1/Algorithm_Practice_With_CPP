#include <iostream>
#include "Benchmark.h"
#include "../SearchingAlgorithms/Searching.h"
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

    SortingBenchmark BubbleSortObj(bubbleSort, randArray);
    SortingBenchmark InsertionSortObj(insertionSort, randArray);
    SortingBenchmark SelectionSortObj(selectionSort, randArray);
    SortingBenchmark MergeSortObj(mergeSort, randArray);
    SortingBenchmark QuickSortObj(quickSort, randArray);
    SortingBenchmark HeapSortObj(heapSort, randArray);
    SortingBenchmark TimSortObj(timSort, randArray);

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
 * @brief Benchmarks the searching algorithms
 ***********************************************************/
void benchmarkSearchingAlgorithms(int length)
{
    int timeToCalcMs = 0;
    // Create and Display User List
    vector<User> userList(length);
    createUsers(userList);
    // displayUsers(userList);

    // Search using Linear Search
    cout << "Searching using Linear Search:" << endl;
    auto start = high_resolution_clock::now();
    int k = findUserByName_LinearSearch("Waldo Emerson", userList);
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop - start);
    timeToCalcMs = time.count();

    cout << "Found: " << userList[k].getFullName() << " at position " << k << " in " << timeToCalcMs << " microseconds" << endl;

    cout << "Searching new table for Waldo Emerson" << endl;

    // Searching using hashmap
    // TODO: implement benchmarking for search algorithms
    User foundUser;
    // displayUsers(userList);

    start = high_resolution_clock::now();
    foundUser = findUser_hashmap(userList, "Waldo Emerson");
    stop = high_resolution_clock::now();
    time = duration_cast<microseconds>(stop - start);
    timeToCalcMs = time.count();

    cout << "FoundUser ID: " << foundUser.getUniqueID() << " in " << timeToCalcMs << " microseconds" << endl;

    return;
}