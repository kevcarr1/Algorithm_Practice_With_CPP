#include <iostream>
#include <vector>

using namespace std;

/*********************************************************
 * @brief Ascending order sort using Selection Sort Algorithm
 *
 * ## Details
 *
 ********************************************************/
void selectionSort(vector<int> &arr)
{
    int minIdx, tmp;
    int size = arr.size();
    // One by one, move the boundary of the unsorted subarray
    for (int i = 0; i < size; i++)
    {
        // Find the minimum element in the unsorted part of the array
        minIdx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }

    return;
}