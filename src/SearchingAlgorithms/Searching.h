#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include "../TestData/GenUsers.h"

int findUserByName_LinearSearch(string name, User *list[]);
void hashmap_example(void);
User findUser_hashmap(vector<User> &userList, string name);

#endif