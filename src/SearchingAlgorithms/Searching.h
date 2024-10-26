#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include "../TestData/GenUsers.h"

User findUserByName_LinearSearch(vector<User> &userList, string name);
User findUser_hashmap(vector<User> &userList, string name);
User findUser_BinarySearch(vector<User> &userList, string name);

#if 0 /* UNUSED */
void hashmap_example(void);
#endif

#endif