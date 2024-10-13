#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Benchmark
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
    Benchmark(void (*func)(vector<int> &arr), vector<int> arr)
    {
        funcPtr = func;
        arrayOfInts = arr;

        calcTimeMs();

        return;
    }

    Benchmark(void (*func)(vector<int> &arr))
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