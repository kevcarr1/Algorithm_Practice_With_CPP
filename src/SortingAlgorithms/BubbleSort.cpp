#include <iostream>
#include <vector>

using namespace std;

/**************************************************************
 * @brief Sorts an array using the Bubble Sort Algorithm
 *
 * ### Details
 *
 * This function sorts the input array by repeatedly stepping
 * through the list, comparing adjacent elements, and swapping
 * them if they are in the wrong order. The process is
 * repeated until the array is fully sorted.
 *
 * @param arr The array to be sorted
 *************************************************************/
void bubbleSort(vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    return;
}