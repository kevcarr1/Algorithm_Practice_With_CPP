#include <iostream>
#include <vector>

using namespace std;

int maxSlidingWindow(const vector<int> &arr, int k)
{
    int size = arr.size();

    if (size < k)
    {
        cout << "==============================================" << endl;
        cout << "ERROR: Array size is less than the window size." << endl;
        return -1;
    }

    int maxSum = 0;
    int currentSum = 0;
    int startIndex = 0;

    // Initialize the first window
    for (int i = 0; i < k; i++)
    {
        currentSum += arr[i];
    }

    maxSum = currentSum;

    // Slide the window across the array
    for (int i = k; i < size; i++)
    {
        currentSum += arr[i] - arr[i - k];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            startIndex = i - k + 1;
        }
    }

    return startIndex;
}