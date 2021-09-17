/*
grid.hpp
Bernard Laughlin
9-16-2021
Header for grid package
*/

#ifndef GRID_HPP
#define GRID_HPP

// creates an empty grid based on the numColumns and numRows provided
void GridInit(int numColumns, int numRows);

// prints the grid
void GridPrint();

// clears grid vector with '.'
void GridClear();

// inserts charcater c into grid
void GridPut(int x, int y, char c);

// return character in grid
char GridGet(int x, int y);

#endif