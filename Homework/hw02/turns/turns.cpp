/*
turns.cpp
Bernard Laughlin
9-16-2021
Program that creates a grid, players can enter 'X' or 'O' 
on the grid and exit with a negative number.
clang++ turns.cpp grid.cpp -o grid
*/

#include <iostream>
#include <vector>
#include "grid.hpp"

using std::cin;
using std::cout;
using std::endl;

// creates a 5 x 5 grid and prints it
void InitGame()
{
    GridInit(5, 5);
    GridPrint();
    cout << "Enter negative number to quit." << endl;
}

bool AskCoordinates(int &x, int &y)
{
    if (x < 0 || y < 0)
    {
        return false;
    }
    return true;
}

void GameLoop()
{
    bool isPositiveNumber;
    bool gameOver = false;
    int x, y;
    int currentPlayer = 1;
    char marker;

    while (gameOver != true)
    {
        if (currentPlayer == 1)
        {
            marker = 'X';
        }
        else
        {
            marker = 'O';
        }
        cout << "Player " << currentPlayer << " enter row and column to place " << marker << " :";
        cin >> x >> y;
        isPositiveNumber = AskCoordinates(x, y);

        if (isPositiveNumber == false)
        {
            cout << "Game Over" << endl;
            gameOver = true;
        }
        else
        {
            if (GridGet(y, x) == '.')
            {
                GridPut(y, x, marker);
                GridPrint();
                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else
                {
                    currentPlayer = 1;
                }
            }
            else
            {
                cout << "Invlaid move" << endl;
            }
        }
    }
}

int main(int argc, char **argv)
{
    InitGame();
    GameLoop();
    return 0;
}