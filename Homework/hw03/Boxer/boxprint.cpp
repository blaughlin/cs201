/*
 * boxprint.cpp
 * Bernard Laughlin 9/24/2021
 * cs201
 * prints a string inside a box made of asterisks defined by user
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
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
