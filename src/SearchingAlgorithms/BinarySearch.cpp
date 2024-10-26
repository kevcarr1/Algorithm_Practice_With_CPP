#include "Searching.h"
#include "../TestData/GenUsers.h"
#include "../TestData/TestData.h"

/**
 * @brief Finds a user in a sorted list of users.
 *
 * Requires ascending sorted array as of now.
 */
User findUser_BinarySearch(vector<User> &userList, string name)
{
    int left = 0;
    int right = userList.size() - 1;

    // displayUsers(list);

    // Sort copy of userList

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (userList[mid] == name)
        {
            return userList[mid]; // Found target
        }
        else if (userList[mid] < name)
        {
            left = mid + 1; // Target is in the right half
        }
        else
        {
            right = mid - 1; // Target is in the left half
        }
    }

    return User("Dummy", "Name");
}