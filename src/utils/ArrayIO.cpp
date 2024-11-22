#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;

/************************************************************
 * @brief Prints the array with an unsorted heading
 ***********************************************************/
void printUnsortedArray(vector<int> &arr)
{
    cout << "Unsorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

/************************************************************
 * @brief Prints the array with a Sorted heading
 ***********************************************************/
void printSortedArray(vector<int> &arr)
{
    cout << "Sorted Array: ";
    printArray(arr);
    cout << endl;

    return;
}

/************************************************************
 * @brief Prints the array
 ***********************************************************/
void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (int i : arr)
        cout << i << " ";
    cout << "]";

    return;
}