#include <iostream>
#include <vector>

using namespace std;

bool checkIntsAscending(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    bool pass = true;

    while (i + 1 < n)
    {
        if (arr[i] > arr[i + 1])
        {
            pass = false;
            break;
        }
        i++;
    }

    return pass;
}

void checkStatus(bool status)
{
    if (status == true)
    {
        cout << "[PASS]" << endl;
    }
    else
    {
        cout << "[FAIL]" << endl;
    }

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