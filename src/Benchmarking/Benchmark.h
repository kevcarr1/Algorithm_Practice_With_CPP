#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <vector>
#include "../TestData/GenUsers.h"

using namespace std;
using namespace std::chrono;

class SortingBenchmark
{
private:
    void (*funcPtr)(vector<int> &arr);
    vector<int> arrayOfInts;
    int timeToCalcMs = 0;

    void calcTimeMs(void)
    {
        auto start = high_resolution_clock::now();
        funcPtr(arrayOfInts);
        auto stop = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(stop - start);

        timeToCalcMs = time.count();
    }

public:
    SortingBenchmark(void (*func)(vector<int> &arr), const vector<int> &arr)
    {
        int size = arr.size();

        arrayOfInts.reserve(size);
        funcPtr = func;
        arrayOfInts = arr;

        calcTimeMs();

        return;
    }

    SortingBenchmark(void (*func)(vector<int> &arr))
    {
        funcPtr = func;
    }

    int getTimeToCalcMs(void)
    {
        return timeToCalcMs;
    }

    bool isAscending(void)
    {
        int size = arrayOfInts.size();
        bool ordered = true;

        for (int i = 0; i < size - 1; i++)
        {
            if (arrayOfInts[i] > arrayOfInts[i + 1])
            {
                ordered = false;
            }
        }

        return ordered;
    }

    bool isDescending(void)
    {
        int size = arrayOfInts.size();
        bool ordered = true;

        for (int i = 0; i < size - 1; i++)
        {
            if (arrayOfInts[i] < arrayOfInts[i + 1])
            {
                ordered = false;
            }
        }

        return ordered;
    }
};

class SearchingBenchmark
{
private:
    User (*funcPtr)(vector<User> &list, string name);
    vector<User> arrayOfUsers;
    int timeToCalcMs = 0;
    string nameToSearch;
    User foundUser;

    void calcTimeMs(void)
    {
        auto start = high_resolution_clock::now();
        foundUser = funcPtr(arrayOfUsers, nameToSearch);
        auto stop = high_resolution_clock::now();
        auto time = duration_cast<microseconds>(stop - start);

        timeToCalcMs = time.count();
    }

public:
    SearchingBenchmark(User (*func)(vector<User> &list, string name), const vector<User> &list, string name)
    {
        funcPtr = func;
        arrayOfUsers = list;
        nameToSearch = name;

        calcTimeMs();

        return;
    }

    int getTimeToCalcMs(void)
    {
        return timeToCalcMs;
    }

    void getStats(void)
    {
        if (foundUser.getUniqueID() != 39212)
        {
            cout << "User was not found. Search complete in " << timeToCalcMs << " microseconds" << endl;
        }
        else
        {
            cout << "Found " << foundUser.getFullName() << " with User ID: " << foundUser.getUniqueID() << " in " << timeToCalcMs << " microseconds" << endl;
        }

        return;
    }
};

// FUNCTION PROTOTYPES
void benchmarkSearchingAlgorithms(int length);
void benchmarkingSortingAlgorithms(int length);

#endif