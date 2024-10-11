#include <vector>

using namespace std;

/**************************************************************
 * @brief Partitions the array around a pivot element
 *
 * ### Details
 *
 * This function takes the last element as the pivot, places the
 * pivot element at its correct position in the sorted array,
 * and places all smaller elements to the left of the pivot and
 * all larger elements to the right of the pivot.
 *
 * @param arr The array to be partitioned
 * @param low The starting index of the array to be partitioned
 * @param high The ending index of the array to be partitioned
 *
 * @return The index of the pivot element after partitioning
 *************************************************************/
static int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++; // Move the smaller element index
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at i+1 position
    swap(arr[i + 1], arr[high]);

    return i + 1; // Return the index of the pivot
}

/**************************************************************
 * @brief Sorts an array using the Quick Sort Algorithm
 *
 * ### Details
 *
 * This function recursively sorts an array by partitioning
 * it around a pivot element.
 *
 * @param arr The array to sort
 * @param low The starting index of the array
 * @param high The ending index of the array
 *************************************************************/
static void quickSort1(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort1(arr, low, pi - 1);
        quickSort1(arr, pi + 1, high);
    }

    return;
}

/**************************************************************
 * @brief Sorts an array using the Quick Sort Algorithm
 *
 * ### Details
 *
 * This function recursively sorts an array by partitioning
 * it around a pivot element.
 *
 * @param arr The array to sort
 *************************************************************/
void quickSort(vector<int> &arr)
{
    quickSort1(arr, 0, arr.size() - 1);

    return;
}
