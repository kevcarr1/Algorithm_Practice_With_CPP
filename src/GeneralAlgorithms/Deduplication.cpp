#include <vector>
#include <algorithm>

using namespace std;

void removeDuplicates(vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        sort(arr.begin(), arr.end());

        auto last = unique(arr.begin(), arr.end());

        arr.erase(last, arr.end());
    }

    return;
}