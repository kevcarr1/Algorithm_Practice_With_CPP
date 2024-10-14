#ifndef TEST_DATA_H
#define TEST_DATA_H

/* Includes */
#include <vector>

using namespace std;

/* Function Prototypes */
vector<int> generateRandomIntArray(int length, int min, int max);
bool checkIntsAscending(vector<int> &arr);
void checkStatus(bool status);

#endif