#include <iostream>
#include <vector>

using namespace std;

/*********************************************************
 * @brief Sorts an array using the Selection Sort Algorithm
 *
 * ## Details
 *
 * This function sorts the input array in-place by
 * repeatedly finding the minimum element from the
 * unsorted part and putting it at the beginning of the
 * sorted part.
 *
 * @param arr The array to be sorted
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