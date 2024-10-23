#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include "../TestData/GenUsers.h"

int findUserByName_LinearSearch(string name, User *list[]);
User findUser_hashmap(vector<User> &userList, string name);

#if 0 /* UNUSED */
void hashmap_example(void);
#endif

#endif