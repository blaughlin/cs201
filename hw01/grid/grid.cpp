/*
grid.cpp
Bernard Laughlin
9/2/2021
Program draws a square grid and allows user to place an x anywhere on the grid
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int width;
    std::cout << "Enter board width as an integer ";
    std::cin >> width;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << " . ";
        }
        std::cout << "\n";
    }
    int row;
    int col;
    std::cout << "Please enter row and column or enter a negative number to end: ";
    while (std::cin >> row >> col)
    {
        if (row < 0 || col < 0)
        {
            break;
        } else if (row > width || col > width || row == 0 || col == 0){
            std::cout << "Can not be zero or greater than board dimensions.\n";
            std::cout << "Please enter row and column or enter a negative number to end: ";
            }
            else
            {
                for (int i = 0; i < width; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        if (row - 1 == i && col - 1 == j)
                        {
                            std::cout << " X ";
                        }
                        else
                        {
                            std::cout << " . ";
                        }
                    }
                    std::cout << "\n";
                }
            std:
                cout << "Please enter row and column or enter a negative number to end: ";
            }
        }
}
