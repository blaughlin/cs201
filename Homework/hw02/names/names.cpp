/*
names.cpp
Bernard Laughlin
9/13/2021
HW 3 for cs121: stores 10 names in a vector, prints out the names, searches for name, sorts vector
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Prompts user to enter 10 names to be stored in a vector
void InputNames(std::vector<std::string> &names)
{
    for (int i = 0; i < 4; i++)
    {
        std::string name;
        std::cout << "Please enter a name: ";
        std::getline(std::cin, name);
        names.push_back(name);
    }
}

// Determines is a name is exists in a vector of names.
bool DoesNameExists(const std::string &nameToFind, const std::vector<std::string> &names)
{
    return std::find(names.begin(), names.end(), nameToFind) != names.end();
}

// Prints out a list of names from a vector of names.
void PrintNames(const std::vector<std::string> &names)
{
    for (int i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << "\n";
    }
}

// Sorts vector of names alphabetically and prints them
void SortNames(std::vector<std::string> &names)
{
    std::sort(names.begin(), names.end());
    PrintNames(names);
}

int main(int argc, char **argv)
{
    std::vector<std::string> names;
    InputNames(names);
    std::cout << DoesNameExists("Ben", names) << "\n";
    PrintNames(names);
    SortNames(names);
    return 0;
}