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
#include "utils/utils.h"
#include "GeneralAlgorithms/GeneralAlgorithms.h"

using namespace std;
using namespace std::chrono;

static void printLearningAlgos(void);

int main()
{
    int length = 10;
    int choice = 1;
    int numUsers = 0;
    // Seed the random number generator with the current time.
    srand(time(0));

    // Introduction
    cout << endl;
    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    printLearningAlgos();
    cout << "What would you like to do?" << endl;
    cout << "1 - Array Sorting" << endl;
    cout << "2 - Searching Examples" << endl;
    cout << "3 - Remove duplicates" << endl;
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

        benchmarkSearchingAlgorithms(numUsers);
    }
    else if (choice == 3)
    {
        cout << endl;
        cout << "Remove Duplicates From Array" << endl;
        cout << "How large do you want to make your array? ";
        cin >> length;

        int min = 0;
        int max = 100;

        vector<int> randArray = generateRandomIntArray(length, min, max);

        cout << "Initial Array:" << endl;
        printArray(randArray);
        cout << endl;

        removeDuplicates(randArray);
        cout << "Unique Array" << endl;
        printArray(randArray);
        cout << endl;
    }
    else
    {
        cout << "Choice is unsupported" << endl;
    }

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
