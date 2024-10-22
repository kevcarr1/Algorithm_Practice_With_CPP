#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "../TestData/GenUsers.h"

using namespace std;

void hashmap_example(void)
{
    vector<string> names = {"Alice", "Bob", "Charlie", "Diana", "Kevin"};
    int size = names.size();

    unordered_map<string, int> hash_table;

    for (int i = 0; i < size; i++)
    {
        hash_table[names[i]] = i;
    }

    string target_name;
    cout << "Enter a name to search: ";
    cin >> target_name;

    auto it = hash_table.find(target_name);

    if (it != hash_table.end())
    {
        cout << "Name found: " << target_name << " at index " << it->second << endl;
    }
    else
    {
        cout << "Name not found" << endl;
    }

    return;
}

User findUser_hashmap(vector<User> &userList, string name)
{
    unordered_map<string, User> hashedUsers;
    int size = userList.size();
    User dummy = User("Dummy", "Name");

    for (int i = 0; i < size; i++)
    {
        hashedUsers[userList[i].getFullName()] = userList[i];
    }

    auto it = hashedUsers.find(name);

    if (it != hashedUsers.end())
    {
        cout << "Found: " << it->second.getFullName() << endl;
        return it->second;
    }
    else
    {
        cout << "Didn't find name";
        return dummy;
    }
}