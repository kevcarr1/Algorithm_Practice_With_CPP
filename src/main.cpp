#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include "TestData/TestData.h"
#include "Benchmarking/Benchmark.h"
#include "SortingAlgorithms/Sorting.h"
#include "Practice/practice.h"
#include "TestData/GenUsers.h"
#include "SearchingAlgorithms/Searching.h"
#include "utils/utils.h"
#include "GeneralAlgorithms/GeneralAlgorithms.h"
#include "Stats/Stats.h"

using namespace std;
using namespace std::chrono;

static void printLearningAlgos(void);

static string statsFilePath()
{
    const char* home = getenv("HOME");
    if (home) return string(home) + "/.algorithm_practice_stats.json";
    return "./algorithm_practice_stats.json";
}

bool checkUnique(vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int length = 10;
    int choice = 1;
    int numUsers = 0;
    // Seed the random number generator with the current time.
    srand(time(0));

    Stats stats;
    stats.load(statsFilePath());

    // Introduction
    cout << endl;
    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    printLearningAlgos();
    cout << "What would you like to do?" << endl;
    cout << "1 - Array Sorting" << endl;
    cout << "2 - Searching Examples" << endl;
    cout << "3 - Remove duplicates" << endl;
    cout << "4 - Sliding Window" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "How long of an array would you like: ";
        cin >> length;
        cout << endl;

        benchmarkingSortingAlgorithms(length);

        cout << endl;

        map<string, bool> results = practiceSortingAlgorithms(length);
        for (auto& [algo, passed] : results) {
            stats.recordResult(algo, passed);
        }
    }
    else if (choice == 2)
    {
        // Prompt User
        cout << endl;
        cout << "Test User Names" << endl;
        cout << "How many users would you like to create? ";
        cin >> numUsers;

        benchmarkSearchingAlgorithms(numUsers);
        cout << endl;

        cout << "Practice Search Algorithms:" << endl;
        map<string, bool> results = practiceSearchingAlgorithms(numUsers);
        for (auto& [algo, passed] : results) {
            stats.recordResult(algo, passed);
        }
    }
    else if (choice == 3)
    {
        cout << endl;
        cout << "Remove Duplicates From Array" << endl;
        cout << "How large do you want to make your array? ";
        cin >> length;
        cout << endl;

        int min = 0;
        int max = 100;

        vector<int> randArray = generateRandomIntArray(length, min, max);

        cout << "Deduplication with C++ Native Features" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Initial Array:";
        printArray(randArray);
        cout << endl;

        auto start = high_resolution_clock::now();
        removeDuplicates(randArray);
        auto stop = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(stop - start);
        cout << "Unique Array: ";
        printArray(randArray);
        cout << endl;
        cout << "Time to execute: " << time.count() << " microseconds" << endl;

        vector<int> randArrayPractice = generateRandomIntArray(length, min, max);

        cout << endl;
        cout << "Practice" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Deduplication Algorithm #1" << endl;
        start = high_resolution_clock::now();
        removeDuplicatesPractice(randArray);
        stop = high_resolution_clock::now();
        time = duration_cast<microseconds>(stop - start);
        cout << "Time to execute: " << time.count() << " microseconds" << endl;
        bool isUnique = checkUnique(randArray);
        if (isUnique)
        {
            cout << "[PASS]" << endl;
        }
        else
        {
            cout << "[FAIL]" << endl;
        }
        stats.recordResult("RemoveDuplicates", isUnique);
    }
    else if (choice == 4)
    {
        int len;
        int windowSize;
        cout << endl;
        cout << "=========================" << endl;
        cout << "Sliding Window Algorithm:" << endl;
        cout << "=========================" << endl;
        cout << "How long of an array do you want: ";
        cin >> len;
        cout << endl;

        int min = 0;
        int max = 100;
        vector<int> randArray = generateRandomIntArray(len, min, max);

        int start = 0;

        printArray(randArray);

        do
        {
            cout << endl;
            cout << "Array size is " << len << endl;
            cout << "How large do you want the window to be: ";
            cin >> windowSize;
            cout << endl;

            start = maxSlidingWindow(randArray, windowSize);
        } while (start == -1);

        cout << endl;
        cout << "Start index is: " << start << endl;

        cout << "[ ";

        int n = randArray.size();

        for (int i = 0; i < n; i++)
        {
            if (i == start)
                cout << "[[";

            cout << randArray[i];

            if (i == start)
                cout << "]]";

            cout << " ";
        }
        cout << "]" << endl;

        int practiceStart;

        practiceStart = maxSlidingWindowPractice(randArray, windowSize);

        bool swPassed = (practiceStart == start);
        cout << "Practice implementation: ";
        if (swPassed)
        {
            cout << "[PASS]" << endl;
        }
        else
        {
            cout << "[FAIL]" << endl;
        }
        stats.recordResult("SlidingWindow", swPassed);
    }
    else
    {
        cout << "Choice is unsupported" << endl;
    }

    stats.save(statsFilePath());
    stats.writeDashboard("./dashboard/stats.js");

    cout << endl;
    cout << "Skill scores updated. Open dashboard/index.html to review your progress." << endl;

    return 0;
}

static void printLearningAlgos(void)
{
    cout << "_________________________________________________________________________________________" << endl;
    cout << "=========================================================================================" << endl;
    cout << "   / /                                _                    / \\_  | |               \\_\\" << endl;
    cout << "   | |   ____  _____  __ ____  _____ (_) ____   ____      / _  \\ | |  ____    ____     ___" << endl;
    cout << "   | |  / __ \\/  _  \\ | | ___|/  _  \\| |/ __ \\ /  _  |   | |_| | | | /  _  | /  _  \\  / _/" << endl;
    cout << "   | |__|  __/| /_/  ||  /    | | | || || | | || |_| |   | ___ | | | | |_| | | |_| | _\\ \\" << endl;
    cout << "   |_____\\___/\\___/\\_\\|_/     |_| |_||_||_| |_|\\___  |   |_| |_| |_| \\___  | \\____/  \\__/" << endl;
    cout << "===================================================| |===================| |===============" << endl;
    cout << "=================================================\\___/=================\\___/===============" << endl;
    cout << "  | |       | |  _   | |  | |         _____" << endl;
    cout << "  | |   _   | | (_) _| |_ | |        |  ___|   _       _" << endl;
    cout << "  | |  / \\  | | | | |_  _|| |___     | |     _| |_   _| |_" << endl;
    cout << "   \\ \\/ / \\/ /  | |  | |  |  _  |    | |___ |_   _| |_   _|" << endl;
    cout << "    \\__/ \\__/   |_|  |_|  |_| |_|    |_____|  |_|     |_|" << endl;
    cout << "=========================================================================================" << endl;
    cout << "=========================================================================================" << endl;
    cout << endl;
    fflush(stdout);

    return;
}
