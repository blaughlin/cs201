// tokenizer.cpp
// Created by Bernard Laughlin on 10/1/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "tokenizer.hpp"
using std::cin;
using std::istringstream;

// Reads in a line and returns true if line contains a string and false if blank
bool ReadLine(std::string & str) {
    std::getline(cin, str);
    return !str.empty();
}

// creates tokens and places them in a vector called tokens and returns length of vector
unsigned StringToTokensWS(const std::string &input, std::vector<std::string> &tokens) {
    istringstream my_stream(input);
    std::string token;
    while (my_stream >> token) {
        tokens.push_back(token);
    }
    tokens.push_back("\n");
    return tokens.size();
}