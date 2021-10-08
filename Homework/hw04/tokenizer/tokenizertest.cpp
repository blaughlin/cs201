// tokenizertest.cpp
// Bernard Laughlin 10-1-2021
// Reads in text and classifies it as a string, integer, whitespace, or identifier

#include <iostream>
#include <string>
#include <vector>
#include "tokenizer.hpp"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<string> myTokens;
    string myString;

    cout << "Please type in some text. When you are done, type \"End\", \"end\", or \"END\"" << endl;
    while(ReadLine(myString)){
        StringToTokensWS(myString, myTokens);
        if (myString == "end" || myString == "End" || myString == "END") break;
    }
    AnalyzeTokens(myTokens);

    return 0;
}
