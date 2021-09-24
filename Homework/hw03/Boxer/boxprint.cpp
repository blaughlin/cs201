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
    while (true) {
        cout << "Enter message followed by a space and number of layers to print," <<
        "\n" << "or 'quit' followed by a positive number to exit: ";
        for (cin >> message >> layers; layers <= 0; cin >> message >> layers){
            cout << "Invalid input layer must be a positive number greater than zero" << endl;
            cout << "Enter message followed by a space and number of layers to print," <<
                 "\n" << "or 'quit' followed by a positive number to exit: ";
        }
        if (message == "quit") {
            break;
        }
        PrintBox(layers, message);
    }
    return 0;
}
