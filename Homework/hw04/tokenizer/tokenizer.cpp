// tokenizer.cpp
// Created by Bernard Laughlin on 10/1/21.
// Source file for tokenizer

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>
#include "tokenizer.hpp"

using std::cin;
using std::cout;
using std::endl;
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
    int count = 0;
    while (my_stream >> token) {
        tokens.push_back(token);
        count += 1;
    }
    if (token != "end" && token!= "END" && token != "End") {
        tokens.push_back("\n");
    }
    return count;
}

// prints and parses tokens into integers, indentifiers, strings, whitespace, or other
void AnalyzeTokens(const std::vector<std::string> &tokens){
    std::string type;
    for (auto token : tokens) {
        std::string spacing = "      ";
        // check for whitespace
        if (token == "\n") {
            type = "[whitespace]";
            token = "";
        // check for string
        } else if (token.at(0) == 34 && token.at(token.length()-1) == 34) {
            type = "[string]";
            spacing  = "          ";
            token = "\\" + token.substr(0, token.size() - 1) + "\\\"";
        } else {
            int intCount = 0;
            int indentifierCount = 0;
            for (auto i : token) {
                // check for integers
                if (i >= 48 && i <= 57) {
                    intCount += 1;
                // check for identifiers
                } else if ( (i >= 65 && i <= 90) || (i >= 97 && i <= 122) || i == 95) {
                    indentifierCount += 1;
                }}

                if (intCount == token.size()) {
                    type = "[integer]";
                    spacing  = "         ";
                } else if (indentifierCount + intCount == token.size()){
                    type = "[identifier]";
                } else {
                    type = "[Other]";
                    spacing  = "           ";
                }
            }
        cout << type << spacing << "\"" <<token << "\"" << endl;
    }
}