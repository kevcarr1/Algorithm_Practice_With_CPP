#include <string>
#include "../TestData/GenUsers.h"

int findUserByName_LinearSearch(string name, User *list[])
{
    int i = 0;
    bool nameFound = false;
    int numUsers = getNumUsers();

    while (i < numUsers && nameFound == false)
    {
        if (list[i]->getFullName() == name)
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