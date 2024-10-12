#include <vector>

using namespace std;

/* The algorithm defines a RUN size, which is the threshold
 * below which the array is sorted using Insertion Sort.
 * This is typically set to 32, as small subarrays benefit
 * from Insertion Sort's simplicity. */
const int RUN = 32; // Typical size for small runs

/**************************************************************
 * @brief Sorts a portion of the array using Insertion Sort
 *
 * ### Details
 *
 * Insertion Sort is used in TimSort for sorting small subarrays,
 * also known as runs, because it is efficient for small datasets
 * and partially sorted data.
 *
 * @param arr The array to be sorted.
 * @param left The starting index of the subarray
 * @param mid The ending index of the subarray
 *************************************************************/
static void insertionSort(vector<int> &arr, int left, int right)
{
    int key, j;

    for (int i = left + 1; i <= right; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    return;
}

/**************************************************************
 * @brief Merges two sorted subarrays.
 *
 * ### Details
 *
 * This function merges two subarrays of arr[]: the first subarray
 * is arr[left..mid] and the second subarray is arr[mid+1..right].
 * It is a critical component of TimSort for combining runs of
 * sorted elements.
 *
 * @param arr The array containing the subarrays to be merged
 * @param left The starting index of the first subarray
 * @param mid The ending index of the first subarray
 * @param right The ending index of the second subarray
 *************************************************************/
static void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = arr[mid + i + 1];

    int i = 0;
    int j = 0;
    int k = left;

    while (i != n1 && j != n2)
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

    while (i != n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j != n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    return;
}

/**************************************************************
 * @brief Compares two ints and returns the smaller value.
 *
 * @param a First integer
 * @param b Second integer
 *************************************************************/
static int min(int a, int b)
{
    int minVal = 0;

    if (a < b)
    {
        minVal = a;
    }
    else
    {
        minVal = b;
    }

    return minVal;
}

/**************************************************************
 * @brief Sorts an array using the Tim Sort Algorithm
 *
 * ### Details
 *
 * TimSort breaks the array into smaller chunks or "runs" and
 * sorts these using Insertion Sort. It then merges the sorted
 * runs into progressively larger sorted sections using a merge
 * operation. TimSort is particularly efficient on partially
 * sorted or nearly sorted data, making it optimal for real-world
 * use cases.
 *
 * @param arr The array to be sorted
 *************************************************************/
void timSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i += RUN)
    {
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
    }

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }

    return;
}