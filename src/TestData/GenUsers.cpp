#include <vector>
#include "GenUsers.h"

using namespace std;
static int numUsers = 0;

User **users;

User **createUsers(int n)
{
    int mysteryPlacement;

    numUsers = n;
    mysteryPlacement = rand() % numUsers;

    users = new User *[numUsers];
    for (int i = 0; i < numUsers; ++i)
    {
        if (i == mysteryPlacement)
        {
            users[i] = new User("Waldo", "Emerson");
        }
        else
        {
            users[i] = new User();
        }
    }

    return users;
}

void createUsers2(vector<User> &users, int numUsers2)
{
    int mysteryPlacement;

    mysteryPlacement = rand() % numUsers;

    for (int i = 0; i < numUsers2; i++)
    {
        if (i == mysteryPlacement)
        {
            users[i] = User("Waldo", "Emerson", 39212);
        }
        else
        {

            users[i] = User();
        }
    }

    return;
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

int getNumUsers(void)
{
    return numUsers;
}