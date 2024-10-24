#include <string>
#include "../TestData/GenUsers.h"

int findUserByName_LinearSearch(string name, vector<User> &userList)
{
    int i = 0;
    bool nameFound = false;
    int numUsers = userList.size();

    while (i < numUsers && nameFound == false)
    {
        if (userList[i].getFullName() == name)
        {
            nameFound = true;
        }
        else
        {
            i++;
        }
    }

    return i;
}