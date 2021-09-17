/*
grid.cpp
Bernard Laughlin
9-16-2021
Functions to create and manipulate a game grid
*/

#include "grid.hpp"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::vector<char> grid;
unsigned numColumns;
unsigned numRows;

void GridInit(int numColumns, int numRows)
{
    ::numColumns = numColumns;
    ::numRows = numRows;
    for (int i = 0; i < numColumns * numRows; i++)
    {
        grid.push_back('.');
    }
}

void GridPrint()
{
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            cout << grid[index];
            index += 1;
        }
        cout << endl;
    }
}

void GridClear()
{
    for (int i = 0; i < numColumns * numRows; i++)
    {
        grid.push_back('.');
    }
}

void GridPut(int x, int y, char c)
{
    int index = y * numColumns + x;
    grid[index] = c;
}

char GridGet(int x, int y) {
    int index = y * numColumns + x;
    return grid[index];
}
