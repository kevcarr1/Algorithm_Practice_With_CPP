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
    cout << " Sorting integers: " << endl;
    cout << "-------------------" << endl;

    cout << "Bubble Sort\t[Ascending]\tTime: " << BubbleSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(BubbleSortObj.isAscending());
    cout << "Bubble Sort\t[Descending]\tTime: " << BubbleSortDescObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(BubbleSortDescObj.isDescending());
    fflush(stdout);
    cout << "Insertion Sort\t[Ascending]\tTime: " << InsertionSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(InsertionSortObj.isAscending());
    cout << "Insertion Sort\t[Descending]\tTime: " << InsertionSortDescObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(InsertionSortDescObj.isDescending());
    cout << "Selection Sort\t\t\tTime: " << SelectionSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(SelectionSortObj.isAscending());
    cout << "Merge Sort\t\t\t\tTime: " << MergeSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(MergeSortObj.isAscending());
    cout << "Quick Sort Time: " << QuickSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(QuickSortObj.isAscending());
    cout << "Heap Sort Time: " << HeapSortObj.getTimeToCalcMs() << " microseconds ";
    checkStatus(HeapSortObj.isAscending());
    cout << "Tim Sort Time: " << TimSortObj.getTimeToCalcMs() << " microseconds ";
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