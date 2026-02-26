#include <iostream>
#include <map>
#include <string>
#include "practice.h"
#include "../Benchmarking/Benchmark.h"
#include "../TestData/TestData.h"
#include "../TestData/GenUsers.h"

static const int WALDO_ID = 39212;

/************************************************************
 * @brief Runs all practice sorting functions and returns
 *        a map of algorithm name -> passed
 ***********************************************************/
map<string, bool> practiceSortingAlgorithms(int length)
{
    map<string, bool> results;
    int min = 0;
    int max = 100;
    vector<int> randArray = generateRandomIntArray(length, min, max);

    cout << "    PRACTICE RESULTS    " << endl;
    cout << "========================" << endl;

    cout << "Practice Bubble Sort: ";
    SortingBenchmark PracticeBubbleSortObj(practiceBubbleSort, randArray);
    int pBubTime = PracticeBubbleSortObj.getTimeToCalcMs();
    cout << pBubTime << " microseconds ";
    bool prBubTest = PracticeBubbleSortObj.isAscending();
    PracticeCheckStatus(prBubTest, pBubTime);
    results["BubbleSort"] = prBubTest;

    cout << "Practice Selection Sort: ";
    SortingBenchmark PracticeSelectionSortObj(practiceSelectionSort, randArray);
    int pSelTime = PracticeSelectionSortObj.getTimeToCalcMs();
    cout << pSelTime << " microseconds ";
    bool prSelTest = PracticeSelectionSortObj.isAscending();
    PracticeCheckStatus(prSelTest, pSelTime);
    results["SelectionSort"] = prSelTest;

    cout << "Practice Insertion Sort: ";
    SortingBenchmark InsertionSortTestObj(practiceInsertionSort, randArray);
    int pInsertTime = InsertionSortTestObj.getTimeToCalcMs();
    cout << pInsertTime << " microseconds ";
    bool prInsertTest = InsertionSortTestObj.isAscending();
    PracticeCheckStatus(prInsertTest, pInsertTime);
    results["InsertionSort"] = prInsertTest;

    cout << "Practice Merge Sort: ";
    SortingBenchmark MergeSortTestObj(practiceMergeSort, randArray);
    int pMergeTime = MergeSortTestObj.getTimeToCalcMs();
    cout << pMergeTime << " microseconds ";
    bool prMergeStatus = MergeSortTestObj.isAscending();
    PracticeCheckStatus(prMergeStatus, pMergeTime);
    results["MergeSort"] = prMergeStatus;

    cout << "Practice Quick Sort: ";
    SortingBenchmark PracticeQuickSortObj(practiceQuickSort, randArray);
    int pQuickTime = PracticeQuickSortObj.getTimeToCalcMs();
    cout << pQuickTime << " microseconds ";
    bool pQuickSortStatus = PracticeQuickSortObj.isAscending();
    PracticeCheckStatus(pQuickSortStatus, pQuickTime);
    results["QuickSort"] = pQuickSortStatus;

    cout << "Practice Heap Sort: ";
    SortingBenchmark HeapSortTestObj(practiceHeapSort, randArray);
    int pHeapTime = HeapSortTestObj.getTimeToCalcMs();
    cout << pHeapTime << " microseconds ";
    bool pHeapSortStatus = HeapSortTestObj.isAscending();
    PracticeCheckStatus(pHeapSortStatus, pHeapTime);
    results["HeapSort"] = pHeapSortStatus;

    cout << "Practice TimSort: ";
    SortingBenchmark TimSortTestObj(practiceTimSort, randArray);
    int pTimSortTime = TimSortTestObj.getTimeToCalcMs();
    cout << pTimSortTime << " microseconds ";
    bool pTimSortStatus = TimSortTestObj.isAscending();
    PracticeCheckStatus(pTimSortStatus, pTimSortTime);
    results["TimSort"] = pTimSortStatus;

    return results;
}

/************************************************************
 * @brief Runs all practice search functions on the same
 *        user list and returns a map of algorithm -> passed
 ***********************************************************/
map<string, bool> practiceSearchingAlgorithms(int numUsers)
{
    map<string, bool> results;
    string userToSearch = "Waldo Emerson";
    vector<User> userList(numUsers);
    createUsers(userList); // always places Waldo Emerson (ID 39212) in the list

    cout << "Practice Linear Search: ";
    SearchingBenchmark linearSearchPractice(findUser_LinearSearchPractice, userList, userToSearch);
    linearSearchPractice.getStats();
    results["LinearSearch"] = (linearSearchPractice.getFoundUserId() == WALDO_ID);

    cout << "Practice HashMap Search: ";
    SearchingBenchmark hashmapSearchPractice(findUser_HashMapPractice, userList, userToSearch);
    hashmapSearchPractice.getStats();
    results["HashMapSearch"] = (hashmapSearchPractice.getFoundUserId() == WALDO_ID);

    return results;
}
