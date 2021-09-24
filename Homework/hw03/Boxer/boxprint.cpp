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
    bool isDone = false;
    while (!isDone) {
        cout << "Enter message followed by a space and number of layers to print: ";
        cin >> message >> layers;
        if (message == "quit") {
            isDone = true;
            break;
        }
        PrintBox(layers, message);
    }
    return 0;
}
