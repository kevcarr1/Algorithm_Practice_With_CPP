#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "TestData.h"

using namespace std;

vector<int> generateRandomIntArray(int length, int min, int max)
{
    int randomValue = 0;
    vector<int> randomArray;
    randomArray.reserve(length); // Allocate memory in advance as opposed to every push to vector

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i)
    {
        randomValue = rand() % (max - min + 1) + min; // Generate random number between min and max
        randomArray.push_back(randomValue);
    }

    return randomArray;
}
