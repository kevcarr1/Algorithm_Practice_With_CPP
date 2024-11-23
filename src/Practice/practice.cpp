#include <iostream>
#include "practice.h"
#include "../Benchmarking/Benchmark.h"
#include "../TestData/TestData.h"

/************************************************************
 * @brief Function groups practice function calls together
 ***********************************************************/
void practiceSortingAlgorithms(int length)
{
    int min = 0;
    int max = 100;
    vector<int> randArray = generateRandomIntArray(length, min, max);

    // PRACTICE
    cout << "    PRACTICE RESULTS    " << endl;
    cout << "========================" << endl;

    cout << "Practice Bubble Sort: ";
    SortingBenchmark PracticeBubbleSortObj(practiceBubbleSort, randArray);
    int pBubTime = PracticeBubbleSortObj.getTimeToCalcMs();
    cout << pBubTime << " microseconds ";
    bool prBubTest = PracticeBubbleSortObj.isAscending();
    PracticeCheckStatus(prBubTest, pBubTime);

    cout << "Practice Selection Sort: ";
    SortingBenchmark PracticeSelectionSortObj(practiceSelectionSort, randArray);
    int pSelTime = PracticeSelectionSortObj.getTimeToCalcMs();
    cout << pSelTime << " microseconds ";
    bool prSelTest = PracticeSelectionSortObj.isAscending();
    PracticeCheckStatus(prSelTest, pSelTime);

    cout << "Practice Insertion Sort: ";
    SortingBenchmark InsertionSortTestObj(practiceInsertionSort, randArray);
    int pInsertTime = InsertionSortTestObj.getTimeToCalcMs();
    cout << pInsertTime << " microseconds ";
    bool prInsertTest = InsertionSortTestObj.isAscending();
    PracticeCheckStatus(prInsertTest, pInsertTime);

    cout << "Practice Merge Sort: ";
    SortingBenchmark MergeSortTestObj(practiceMergeSort, randArray);
    int pMergeTime = MergeSortTestObj.getTimeToCalcMs();
    cout << pMergeTime << " microseconds ";
    auto prMergeStatus = MergeSortTestObj.isAscending();
    PracticeCheckStatus(prMergeStatus, pMergeTime);

    cout << "Practice Quick Sort: ";
    SortingBenchmark PracticeQuickSortObj(practiceQuickSort, randArray);
    int pQuickTime = PracticeQuickSortObj.getTimeToCalcMs();
    cout << pQuickTime << " microseconds ";
    auto pQuickSortStatus = PracticeQuickSortObj.isAscending();
    PracticeCheckStatus(pQuickSortStatus, pQuickTime);

    cout << "Practice Heap Sort: ";
    SortingBenchmark HeapSortTestObj(practiceHeapSort, randArray);
    int pHeapTime = HeapSortTestObj.getTimeToCalcMs();
    cout << pHeapTime << " microseconds ";
    bool pHeapSortStatus = HeapSortTestObj.isAscending();
    PracticeCheckStatus(pHeapSortStatus, pHeapTime);

    cout << "Practice TimSort: ";
    SortingBenchmark TimSortTestObj(practiceTimSort, randArray);
    int pTimSortTime = TimSortTestObj.getTimeToCalcMs();
    cout << pTimSortTime << " microseconds ";
    auto pTimSortStatus = TimSortTestObj.isAscending();
    PracticeCheckStatus(pTimSortStatus, pTimSortTime);

    return;
}

void practiceSearchingAlgorithms(int numUsers)
{
    string userToSearch = "Waldo Emerson";
    vector<User> userList(numUsers);
    User foundUser;

    // Create User random list and name to search.
    cout << "Practice Linear Search: ";
    SearchingBenchmark linearSearchPractice = SearchingBenchmark(findUser_LinearSearchPractice, userList, userToSearch);
    linearSearchPractice.getStats();

    cout << "Practice HashMap Search: ";
    SearchingBenchmark hashmapSearchPractice = SearchingBenchmark(findUser_HashMapPractice, userList, userToSearch);
    hashmapSearchPractice.getStats();

    return;
}