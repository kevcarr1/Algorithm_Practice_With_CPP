#include <vector>

using namespace std;

/**************************************************************
 * @brief Converts a subtree into a max heap
 *
 * ### Details
 *
 * This function assumes that the binary trees rooted at left
 * and right children of 'i' are max heaps but that 'arr[i]'
 * may be smaller than its children violating the max heap
 * property. This function restores the max heap property
 * for the tree rooted at 'i'.
 *
 * @param arr The array representing the heap
 * @param n The size of the heap
 * @param i The index of the current node
 *************************************************************/
static void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left Child
    int right = 2 * i + 2; // Right Child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // if right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not the root
    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap root with the largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }

    return;
}

/**************************************************************
 * @brief Sorts an array using the Heap Sort Algorithm
 *
 * ### Details
 *
 * This function sorts the input array by first building a max
 * heap and then repeatedly extracting the largest element and
 * moving it to the end of the array, reducing the heap size by
 * one, and restoring the heap property by calling the
 * 'heapify' function
 *
 * @param arr The array representing the heap
 *************************************************************/
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // Move the current root (largest) to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced map
        heapify(arr, i, 0);
    }

    return;
}
