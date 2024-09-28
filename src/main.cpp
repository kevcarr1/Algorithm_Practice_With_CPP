#include <iostream>
#include "TestData/TestData.h"

using namespace std;

int main()
{
    int length = 10;
    int min = 1;
    int max = 100;

    vector<int> randArray1 = generateRandomIntArray(length, min, max);

    cout << "Welcome to Learning Algorithms with CPP!" << endl;
    cout << endl;
    cout << "To Start, implement a Bubble Sort on the following array:" << endl;

    for (int i : randArray1)
        cout << i << " ";
    cout << endl;

    // Implement Bubble Sort here

    return 0;
}