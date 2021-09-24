/*
 * boxprint.cpp
 * Bernard Laughlin 9/24/2021
 * prints a string inside a box made of asterisks
 */
#include <iostream>
#include <string>
#include "boxer.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    int layers;
    string message;

    cout << "Enter message followed by a space and number of layers to print: ";
    cin >> message >> layers;
    PrintBox(layers, message);
    return 0;
}
