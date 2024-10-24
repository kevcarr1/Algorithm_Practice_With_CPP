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

        benchmarkSearchingAlgorithms(numUsers);
    }
    else
    {
        cout << "Choice is unsupported" << endl;
    }

    return 0;
}
