/*
Scores.cpp
Bernard Laughlin 
9/19/2021
Prompts user to input names and scores, print results, search for a name, or search for scores
*/

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> names;
vector<int> scores;

// Searches a vector for duplicate names, returns true if duplicate found
bool CheckForDuplicates(vector<string> nameVector)
{
    string currentName;
    for (int i = 0; i < nameVector.size(); i++)
    {
        currentName = nameVector[i];
        for (int j = i + 1; j < nameVector.size() - 1; j++)
        {
            if (currentName == nameVector[j])
            {
                return true;
            }
        }
    }
    return false;
}

// Add names and score to vector names and scores
// Need to error check for invalid strings and numbers
void AddNamesAndScores()
{
    bool isDone = false;
    string name;
    int score;



    while (!isDone)
    {
        cout << "Enter a name followed by a score or Noname 0 to quit: ";
        cin >> name >> score;
        if (name == "Noname" && score == 0)
        {
            isDone = true;
            break;
        }

        if (cin.fail())
        {
            cout << "Invlaid input" << endl;
            // cout << "Enter a name followed by a score or Noname 0 to quit: ";
            cin.clear();
            cin.ignore();
            // cin >> name >> score;
            // isDone = true;
            // break;
        }

        names.push_back(name);
        scores.push_back(score);
    }
}

// Prints names and scores only if each name is unique.
void PrintResults()
{
    if (CheckForDuplicates(names) == true)
    {
        cout << "Error: duplicate names detected" << endl;
    }
    else
    {
        for (int i = 0; i < names.size(); i++)
        {
            cout << names[i] << ": " << scores[i] << endl;
        }
    }
}

// Searches for name and prints out their score
void SearchForName()
{
    string name;
    bool foundName = false;
    cout << "Enter name to find: ";
    cin >> name;

    for (int i = 0; i < names.size(); i++)
    {
        if (name == names[i])
        {
            cout << scores[i] << endl;
            foundName = true;
        }
    }
    if (!foundName)
    {
        cout << "name not found." << endl;
    }
}

// Prints out all names who have that score.
void SearchForScore()
{
    vector<string> foundScores;
    int score;
    cout << "Enter a score to find: ";
    cin >> score;
    for (int i = 0; i < scores.size(); i++)
    {
        if (score == scores[i])
        {
            foundScores.push_back(names[i]);
        }
    }
    if (foundScores.size() > 0)
    {
        //Print out names
        for (int i = 0; i < foundScores.size(); i++)
        {
            cout << foundScores[i] << endl;
        }
    }
    else
    {
        cout << "score not found." << endl;
    }
}

// Prompts user to input names and scores, print results, search for a name, or search for scores
int main()
{
    bool isDone = false;
    int choice;

    while (!isDone)
    {
        cout << "1) to add names and score." << endl;
        cout << "2) to print out names and score." << endl;
        cout << "3) to search for a name" << endl;
        cout << "4) to search for a score" << endl;
        cout << "Enter choice ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddNamesAndScores();
            break;
        case 2:
            PrintResults();
            break;
        case 3:
            SearchForName();
            break;
        case 4:
            SearchForScore();
            break;
        default:
            cout << "Invalid input." << endl;
            isDone = true;
            break;
        }
    }
    return 0;
}