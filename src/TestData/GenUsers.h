#ifndef GEN_USERS_H
#define GEN_USERS_H

#include <string>
#include <cstdlib> // rand()
#include <iostream>

using namespace std;

static const string firstNames[] = {"James", "Michael", "Robert", "John", "David",
                                    "Wiliam", "Richard", "Joseph", "Thomas", "Christopher",
                                    "Mary", "Patricia", "Jennifer", "Linda", "Elizabeth",
                                    "Barbara", "Susan", "Jessica", "Karen", "Sarah"};

static const string lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones",
                                   "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
                                   "Hernandez", "Lopez", "Gonzales", "Wilson", "Anderson",
                                   "Thomas", "Taylor", "Moore", "Jackson", "Martin"};

class User
{
private:
    string firstName;
    string lastName;

public:
    User(void)
    {
        int firstNameIdx = rand() % 20;
        int lastNameIdx = rand() % 20;

        firstName = firstNames[firstNameIdx];
        lastName = lastNames[lastNameIdx];
    }

    string getFullName(void)
    {
        return firstName + " " + lastName;
    }
};

void createUsers(int n);
void displayUsers(void);
void deleteUsers(void);

#endif