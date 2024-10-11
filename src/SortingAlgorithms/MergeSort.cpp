#include <vector>

using namespace std;

/**************************************************************
 * @brief Merges two subarrays of arr[]
 *
 * ### Details
 *
 * The first subarray is arr[left..mid]
 * The second subarray is arr[mid+1..right]
 *
 * @param arr The array to be merge
 * @param left The starting index of the left subarray
 * @param mid The ending index of the left subarray and midpoint
 *            of the merge
 * @param right The ending index of the right subarray
 *************************************************************/
static void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left sub-array
    int n2 = right - mid;    // Size of the right sub-array

    // Create temporary arrays
    vector<int> leftArray(n1), rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[1..r]
    int i = 0;    // Initial index of the left sub-array
    int j = 0;    // Initial index of the right sub-array
    int k = left; // Initial index of the merged sub-array

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    return;
}

/**************************************************************
 * @brief Sorts an array using the Merge Sort Algorithm
 *
 * ### Details
 *
 * This function recursively divides the array into two halves
 * and sorts the halves before merging them back together in
 * sorted order.
 *
 * @param arr The array to be sorted
 * @param left The starting index of the array
 * @param right The ending index of the array
 *************************************************************/
static void mergeSort1(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort1(arr, left, mid);
        mergeSort1(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }

    return;
}

/**************************************************************
 * @brief Sorts an array using the Merge Sort Algorithm
 *
 * ### Details
 *
 * This function recursively divides the array into two halves
 * and sorts the halves before merging them back together in
 * sorted order.
 *
 * @param arr The array to be sorted
 *************************************************************/
void mergeSort(vector<int> &arr)
{
    mergeSort1(arr, 0, arr.size() - 1);

    return;
}