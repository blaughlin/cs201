/*
dotcross.cpp
Bernard Laughlin 
9/3/2021
Program calculates the dot product and cross product of a 3-component vector.
*/

#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::setprecision;

int main () {

    float vectorA_x;
    float vectorA_y;
    float vectorA_z;
    float vectorB_x;
    float vectorB_y;
    float vectorB_z;

    std::cout << "Enter x, y, z for vector A: ";
    std::cin >> vectorA_x >> vectorA_y >> vectorA_z;
    std::cout << "Enter x, y, z for vector B: ";
    std::cin >> vectorB_x >> vectorB_y >> vectorB_z;
    float dotProduct = vectorA_x * vectorB_x + vectorA_y * vectorB_y + vectorA_z * vectorB_z;
    float cX =  vectorA_y * vectorB_z - vectorA_z * vectorB_y;
    float cY = vectorA_z * vectorB_x - vectorA_x * vectorB_z;
    float cZ = vectorA_x * vectorB_y - vectorA_y * vectorB_x;

    std::cout << "The dot product of vector A and B is " << std::setprecision(5) << dotProduct << "\n";
    std::cout << "A cross B = (" << std::setprecision(5) << cX << ", " << std::setprecision(5) << cY << ", " << std::setprecision(5) << cZ << ")\n";
    return 0;
}