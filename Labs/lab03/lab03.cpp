/*
lab03.cpp
Bernard Laughlin
9/3/2021
iteration lab assignment for cs201
*/

#include <iostream>

using std::cout;

int main()
{
    // print out the numbers 1 thorugh 20
    int i = 1;
    while (i <= 20)
    {
        std::cout << i << "\n";
        i++;
    }

    // print a 60 x 10 grid
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    return 0;
}