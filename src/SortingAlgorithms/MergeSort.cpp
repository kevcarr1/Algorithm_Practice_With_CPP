#include <vector>

using namespace std;

// Support function
void merge(vector<int> &arr, int left, int mid, int right);

/**************************************************************
 * @brief Merge Sort
 *************************************************************/
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }

    return;
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of the left sub-array
    int n2 = right - mid;    // Size of the right sub-array

    // Create temporary arrays
    vector<int> leftArray(n1), rightArray(n2);

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + 1];
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