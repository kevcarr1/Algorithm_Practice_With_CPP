#include <string>
#include "../TestData/GenUsers.h"

User findUserByName_LinearSearch(vector<User> &userList, string name)
{
    int i = 0;
    bool nameFound = false;
    int numUsers = userList.size();
    User foundUser;

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

    if (nameFound == true)
    {
        foundUser = userList[i];
    }
    else
    {
        foundUser = User("Dummy", "Name");
    }

    return foundUser;
}