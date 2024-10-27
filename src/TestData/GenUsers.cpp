#include <vector>
#include "GenUsers.h"

using namespace std;

void createUsers(vector<User> &users)
{
    int mysteryPlacement;
    int size = users.size();

    mysteryPlacement = rand() % size;

    for (int i = 0; i < size; i++)
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

void displayUsers(vector<User> &userList)
{
    int j = 0;
    string name;
    int size = userList.size();

    cout << "Users: " << endl;

    for (int i = 0; i < size; ++i)
    {
        name = userList[i].getFullName();

        if (i < size - 1)
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

    cout << endl;

    return;
}