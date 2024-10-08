#include <vector>

using namespace std;

static void heapify(vector<int> &arr, int n, int i);

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

// Function to heapify a subtree rooted with node i, where n is the size of the heap
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