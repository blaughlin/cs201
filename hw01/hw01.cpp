/*
hw01.cpp
Bernard Laughlin
9/2/2021
Homework iteration assignment for cs201
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int height;
    std::cout << "Please enter height: ";
    std::cin >> height;
    std::cout << "Height is " << height << "\n";
    int whiteSpace = height - 1;
    int counter = 1;

    // Create top of diamond
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < whiteSpace; j++)
        {
            std::cout << " ";
        }
        for (int k = 0; k < counter; k++)
        {
            std::cout << "#";
        }
        whiteSpace--;
        counter += 2;
        std::cout << "\n";
    }

    // Create bottom of diamond
    whiteSpace += 2;
    counter -= 4;
    for (int i = 2; i <= height; i++)
    {
        for (int j = 0; j < whiteSpace; j++)
        {
            std::cout << " ";
        }
        for (int k = 0; k < counter; k++)
        {
            std::cout << "#";
        }
        whiteSpace++;
        counter -= 2;
        std::cout << "\n";
    }
    return 0;
}