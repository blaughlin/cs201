// tokenizertest.cpp
// Bernard Laughlin 10-1-2021
//

#include <iostream>
#include <string>
#include "tokenizer.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
    cout << "Please type in some text. When you are done, type \"End\", \"end\", oe \"END\"" << endl;
    string myString;
    cout << ReadLine(myString);
    return 0;
}
