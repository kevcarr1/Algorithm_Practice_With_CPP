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
    SortingBenchmark BubbleSortDescObj(bubbleSortDesc, randArray);
    SortingBenchmark InsertionSortObj(insertionSort, randArray);
    SortingBenchmark InsertionSortDescObj(insertionSortDesc, randArray);
    SortingBenchmark SelectionSortObj(selectionSort, randArray);
    SortingBenchmark MergeSortObj(mergeSort, randArray);
    SortingBenchmark QuickSortObj(quickSort, randArray);
    SortingBenchmark HeapSortObj(heapSort, randArray);
    SortingBenchmark TimSortObj(timSort, randArray);

    cout << "     Benchmark Summary:     " << endl;
    cout << "============================" << endl;
    cout << "Bubble Sort [Ascending]  Time: " << BubbleSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(BubbleSortObj.isAscending());
    cout << "Bubble Sort [Descending] Time: " << BubbleSortDescObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(BubbleSortDescObj.isDescending());
    fflush(stdout);
    cout << "Insertion Sort [Ascending]  Time: " << InsertionSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(InsertionSortObj.isAscending());
    cout << "Insertion Sort [Descending] Time: " << InsertionSortDescObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(InsertionSortDescObj.isDescending());
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
    // Create and Display User List
    string userToSearch = "Waldo Emerson";
    vector<User> userList(length);
    User foundUser;

    createUsers(userList);
    // displayUsers(userList);

    // Search using Linear Search
    cout << "Searching using Linear Search:" << endl;
    SearchingBenchmark linearSearch = SearchingBenchmark(findUserByName_LinearSearch, userList, userToSearch);
    linearSearch.getStats();

#if 0 /* Sanity check to ensure next search does not return the user found by the first search */
    foundUser = User("Dummy", "Name");
    cout << "Reseting foundUser Var: " << foundUser.getFullName() << endl;
#endif

    // Searching using hashmap
    SearchingBenchmark hashmapSearch = SearchingBenchmark(findUser_hashmap, userList, userToSearch);
    hashmapSearch.getStats();

    return;
}