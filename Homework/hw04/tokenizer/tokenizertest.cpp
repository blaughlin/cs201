// tokenizertest.cpp
// Bernard Laughlin 10-1-2021
//

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
    cout << "Please type in some text. When you are done, type \"End\", \"end\", oe \"END\"" << endl;
    string myString;
    cout << ReadLine(myString) << endl;
    cout << myString << endl;
    cout << StringToTokensWS(myString, myTokens) << endl;
    for (auto i : myTokens) {
        cout << i << " ";
    }
    return 0;
}
