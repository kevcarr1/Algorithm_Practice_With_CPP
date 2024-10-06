#include <vector>

using namespace std;

void quickSort1(vector<int> &arr, int low, int high);
static int partition(vector<int> &arr, int low, int high);

void quickSort(vector<int> &arr)
{
    quickSort1(arr, 0, arr.size()-1);

    return;
}

void quickSort1(vector<int> &arr, int low, int high)
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

// Partition function to place the pivot in the correct position
static int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for(int j = low; j < high; j++)
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