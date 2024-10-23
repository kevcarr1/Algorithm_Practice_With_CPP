#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestData/TestData.h"
#include "Benchmarking/Benchmark.h"
#include "SortingAlgorithms/Sorting.h"
#include "Practice/practice.h"
#include "TestData/GenUsers.h"
#include "SearchingAlgorithms/Searching.h"

using namespace std;
using namespace std::chrono;

void PracticeCheckStatus(bool testResult, int time);

static void practiceSortingAlgorithms(int length);

int main()
{
    int length = 10;
    int choice = 1;
    int numUsers = 0;
    // Seed the random number generator with the current time.
    srand(time(0));

    // Introduction
    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "1 - Array Sorting" << endl;
    cout << "2 - Searching Examples" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "How long of an array would you like: ";
        cin >> length;
        cout << endl;

        benchmarkingSortingAlgorithms(length);

        cout << endl;

        practiceSortingAlgorithms(length);
    }
    else if (choice == 2)
    {
        // Prompt User
        cout << endl;
        cout << "Test User Names" << endl;
        cout << "How many users would you like to create? ";
        cin >> numUsers;

        // Create and Display User List
        // TODO: replace array of User pointers with scoped User vector
        User **users = createUsers(numUsers);
        displayUsers();

        // Search using Linear Search
        cout << "Searching using Linear Search:" << endl;
        int k = findUserByName_LinearSearch("Waldo Emerson", users);

        cout << "Found: " << users[k]->getFullName() << " at position " << k << endl;

        cout << endl;

        deleteUsers();

        cout << "Searching new table for Waldo Emerson" << endl;

        // Searching using hashmap
        // TODO: implement benchmarking for search algorithms
        vector<User> userList(numUsers);
        User foundUser;

        createUsers2(userList, numUsers);

        foundUser = findUser_hashmap(userList, "Waldo Emerson");

        cout << "FoundUser ID: " << foundUser.getUniqueID() << endl;
    }
    else
    {
        cout << "Choice is unsupported" << endl;
    }

    return 0;
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
