#include "GenUsers.h"

using namespace std;
static int numUsers = 0;

User **users;

void createUsers(int n)
{
    numUsers = n;
    users = new User *[numUsers];
    for (int i = 0; i < numUsers; ++i)
    {
        users[i] = new User();
    }
}

void displayUsers(void)
{
    int j = 0;
    string name;

    for (int i = 0; i < numUsers; ++i)
    {
        name = users[i]->getFullName();

        if (i < numUsers - 1)
        {
            cout << name;

            // Create tabs based on length of name for
            // column alignment
            if (name.length() >= 15)
            {
                cout << ",\t";
            }
            else
            {
                cout << ",\t\t";
            }
        }
        else
        {
            cout << name;
        }

        if (j == 4)
        {
            cout << endl;
            j = 0;
        }
        else
        {
            j++;
        }
    }

    return;
}

void deleteUsers(void)
{
    for (int i = 0; i < numUsers; i++)
    {
        delete users[i];
    }

    delete[] users;

    return;
}