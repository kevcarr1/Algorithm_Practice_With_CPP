#include <iostream>
#include "TestData/TestData.h"
#include "SortingAlgorithms/Sorting.h"

using namespace std;

void printSortedArray(vector<int> &arr);
void printUnsortedArray(vector<int> &arr);
void printArray(vector<int> &arr);

int main()
{
    int length = 10;
    int min = 1;
    int max = 100;

    vector<int> randArray = generateRandomIntArray(length, min, max);

    vector<int> randArray1 = randArray;

    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    cout << endl;
    cout << "Here's an example of Bubble Sort on the following array:" << endl;

    printUnsortedArray(randArray1);
    bubbleSort(randArray1);
    printSortedArray(randArray1);

    cout << endl;

    vector<int> randArray2 = randArray;

    cout << "Here's an example of Insertion Sort to sort the same array:" << endl;

    printUnsortedArray(randArray2);
    insertionSort(randArray2);
    printSortedArray(randArray2);

    cout << endl;

    vector<int> randArray3 = randArray;
    cout << "Here's an example of Selection Sort to sort the same array:" << endl;

    printUnsortedArray(randArray3);
    selectionSort(randArray3);
    printSortedArray(randArray3);

    cout << endl;

    cout << "Next, we will compare the runtime of the algorithms and make the array configurable." << endl;

    return 0;
}

void printUnsortedArray(vector<int> &arr)
{
    cout << "Unsorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

void printSortedArray(vector<int> &arr)
{
    cout << "Sorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (int i : arr)
        cout << i << " ";
    cout << "]";

    return;
}