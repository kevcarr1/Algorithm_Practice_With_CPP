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
    SortingBenchmark SelectionSortDescObj(SelectionSortDescending, randArray);
    SortingBenchmark MergeSortObj(mergeSort, randArray);
    SortingBenchmark QuickSortObj(quickSort, randArray);
    SortingBenchmark HeapSortObj(heapSort, randArray);
    SortingBenchmark TimSortObj(timSort, randArray);

    cout << "     Benchmark Summary:     " << endl;
    cout << "============================" << endl;
    cout << " Sorting integers: " << endl;
    cout << "-------------------" << endl;

    cout << "Bubble Sort\t[Ascending]\tTime: " << BubbleSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(BubbleSortObj.isAscending());
    cout << "Bubble Sort\t[Descending]\tTime: " << BubbleSortDescObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(BubbleSortDescObj.isDescending());
    fflush(stdout);
    cout << "Insertion Sort\t[Ascending]\tTime: " << InsertionSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(InsertionSortObj.isAscending());
    cout << "Insertion Sort\t[Descending]\tTime: " << InsertionSortDescObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(InsertionSortDescObj.isDescending());
    cout << "Selection Sort\t[Ascending]\tTime: " << SelectionSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(SelectionSortObj.isAscending());
    cout << "Selection Sort\t[Descending]\tTime: " << SelectionSortDescObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(SelectionSortDescObj.isDescending());
    cout << "Merge Sort\t[Ascending]\tTime: " << MergeSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(MergeSortObj.isAscending());
    cout << "Quick Sort\t[Ascending]\tTime: " << QuickSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(QuickSortObj.isAscending());
    cout << "Heap Sort\t[Ascending]\tTime: " << HeapSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(HeapSortObj.isAscending());
    cout << "Tim Sort\t[Ascending]\tTime: " << TimSortObj.getTimeToCalcMs() << " microseconds\t";
    checkStatus(TimSortObj.isAscending());

    /*
        cout << endl;
        cout << "Sorting Users:" << endl;
        cout << "--------------" << endl;
        */

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

    // Searching using hashmap TODO: Creation of hashmap currently included as part of benchmark, remove
    cout << "Searching using Hashing Search:" << endl;
    SearchingBenchmark hashmapSearch = SearchingBenchmark(findUser_hashmap, userList, userToSearch);
    hashmapSearch.getStats();

    vector<User> userListSorted = userList;

    sortUsers(userListSorted);

    displayUsers(userListSorted);

    cout << "Searching using Binary Search:" << endl;
    SearchingBenchmark binarySearch = SearchingBenchmark(findUser_BinarySearch, userListSorted, userToSearch);
    binarySearch.getStats();

    return;
}