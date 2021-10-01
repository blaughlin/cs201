// tokenizer.cpp
// Created by Bernard Laughlin on 10/1/21.
//

#include "tokenizer.hpp"
#include <iostream>
#include <string>

using std::cin;

// Reads in a line and returns true if line contains a string and false if blank
bool ReadLine(std::string & str) {
    std::getline(cin, str);
    return !str.empty();
}