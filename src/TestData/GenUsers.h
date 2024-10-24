#ifndef GEN_USERS_H
#define GEN_USERS_H

#include <string>
#include <cstdlib> // rand()
#include <iostream>
#include <vector>

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
    int uniqueID;

public:
    User(void)
    {
        int firstNameIdx = rand() % 20;
        int lastNameIdx = rand() % 20;

        firstName = firstNames[firstNameIdx];
        lastName = lastNames[lastNameIdx];

        uniqueID = rand() % 100000;
    }

    User(const string first, const string last) : firstName(first), lastName(last)
    {
        uniqueID = rand() % 100000;
    }

    User(const string first, const string last, int id) : firstName{first}, lastName{last}, uniqueID{id} {}

    string getFullName(void)
    {
        return firstName + " " + lastName;
    }

    int getUniqueID(void)
    {
        return uniqueID;
    }

    bool operator==(const User &other) const
    {
        return firstName == other.firstName && lastName == other.lastName;
    }
};

// Function Prototypes

void createUsers(vector<User> &users);
void createUsers2(vector<User> &users);
void displayUsers(vector<User> &userList);

#endif