#include <iostream>
#include <vector>
#include "../TestData/GenUsers.h"

using namespace std;

/*********************************************************/
/** @brief Insertion Sort for a vector of ints. Will
 *         sort in ascending order
 *
 * ### Details
 *
 * - Key Concept:
 *      The 'key' holds the value of the current
 *      element being compared.
 *
 * - Comparison Loop:
 *      The inner 'while' loop compares the current 'key'
 *      with previous elements. If they are greater than
 *      'key', they are shifted to the right.
 *
 * - Insertion:
 *      Once the correct position is found, the 'key' is
 *      inserted.
 *
 * @param arr The array to be sorted
 *********************************************************/
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }

    return;
}

void insertionSortDesc(vector<int> &arr)
{
    int n = arr.size();
    int key, j;

    for (int i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        key = arr[j + 1];
    }

    return;
}

void sortUsers(vector<User> &userList)
{
    int size = userList.size();
    User key;
    int j;

    for (int i = 0; i < size; i++)
    {
        key = userList[i];
        j = i - 1;

        while (j >= 0 && userList[j] > key)
        {
            userList[j + 1] = userList[j];
            j = j - 1;
        }

        userList[j + 1] = key;
    }
    return;
}