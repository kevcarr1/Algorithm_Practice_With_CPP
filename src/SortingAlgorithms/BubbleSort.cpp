#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    return;
}