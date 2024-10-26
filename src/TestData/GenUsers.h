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
    string fullName;
    int uniqueID;

public:
    User(void)
    {
        int firstNameIdx = rand() % 20;
        int lastNameIdx = rand() % 20;

        firstName = firstNames[firstNameIdx];
        lastName = lastNames[lastNameIdx];
        fullName = firstName + " " + lastName;

        uniqueID = rand() % 100000;
    }

    User(const string first, const string last) : firstName(first), lastName(last)
    {
        fullName = firstName + " " + lastName;
        uniqueID = rand() % 100000;
    }

    User(const string first, const string last, int id) : firstName{first}, lastName{last}, uniqueID{id}
    {
        fullName = firstName + " " + lastName;
    }

    string getFullName(void)
    {
        return fullName;
    }

    string getFirstName(void)
    {
        return firstName;
    }

    string getLastName(void)
    {
        return lastName;
    }

    int getUniqueID(void)
    {
        return uniqueID;
    }

    bool operator==(const User &other) const
    {
        return firstName == other.firstName && lastName == other.lastName;
    }

    bool operator==(const string name) const
    {
        return fullName == name;
    }

    bool operator<(const User &other) const
    {
        bool lessThan = false;

        if (fullName < other.fullName)
        {
            lessThan = true;
        }

        return lessThan;
    }

    bool operator<(const string name) const
    {
        bool lessThan = false;

        if (fullName < name)
        {
            lessThan = true;
        }

        return lessThan;
    }

    bool operator>(const User &other) const
    {
        bool greaterThan = false;

        if (fullName > other.fullName)
        {
            greaterThan = true;
        }

        return greaterThan;
    }

    bool operator>(const string name) const
    {
        bool greaterThan = false;

        if (fullName < name)
        {
            greaterThan = true;
        }

        return greaterThan;
    }
};

// Function Prototypes

void createUsers(vector<User> &users);
void createUsers2(vector<User> &users);
void displayUsers(vector<User> &userList);

#endif