// boxer.cpp
// Created by Bernard Laughlin on 9/24/21.
// cs201
// Source file for boxer.cpp

#include "boxer.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


// Prints top or bottom of box
void PrintBoxLayers(int layers, string msg) {
    int width = msg.size()  + 6;
    for(int i = 0; i < layers; i++){
        for(int j = 0; j < width; j++) {
            cout << '*';
        }
        cout << endl;
    }
}

void PrintBox(int layers, std::string msg){
    int width = msg.size()  + 6;

    // Prints the top of box
    PrintBoxLayers(layers, msg);

    // Prints message in middle of box
    for(int i = 0; i <= 2; i++){
        if (i % 2 == 0) {
            cout << "** ";
            for (int j = 0; j < msg.size(); j++){
                cout << " ";
            }
            cout << " **" << endl;
        } else {
            cout << "** " << msg << " **" << endl;
        }
    }

    // Prints bottom of box
    PrintBoxLayers(layers, msg);
}