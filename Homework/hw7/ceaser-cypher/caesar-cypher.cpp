// caesar-cypher.cpp
// Bernard Laughlin 11/16/2021
// A C++ program that repeatedly inputs a line of text and an integer used a shift. It
// applies the Caesar Cypher with that shift to the text and output the result.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include<sstream>
using std::istringstream;
using std::getline;

// gets user input and returns true if user typed 'q'
bool GetInput(string & msg) {
    string input;
    while (true) {
        cout << "Enter message to encode or 'q' to quit: ";
        getline(cin, input);
        istringstream istream(input);
        istream >> msg;
        if (msg == "q") {
            return true;
        }
        if (!istream) cout << "Invalid input." << endl;
        else break;
    }
    return false;
}

// Gets shift number from user
void GetShift(int & shift) {
    string input;
    while (true) {
      cout << "Enter number to shift letters by: ";
      getline(cin, input);
      istringstream istream(input);
      istream >> shift;
      if (!istream) cout << "Invalid input." << endl;
      else break;
    }
}

// Shifts every letter in message by shift count.
void Encode(const string & msg, const int & shift) {
    for (auto i : msg) {
        // handle upper case
        if (i >= 65 && i <= 90) {
            if ( i + shift > 90){
                cout << char(65+(i + shift - 65) % 26);
            } else cout << char(i + shift);
            // handle lower case
        } else if (i >= 97 && i <= 122) {
            if ( i + shift > 122){
                cout << char(97+(i + shift - 97) % 26);
            } else cout << char(i + shift);
            // everything else
        } else cout << i;
    }
    cout << endl;
}


int main() {
    string message;
    int shift = 0;
    while (!GetInput(message)){
        GetShift(shift);
        Encode(message, shift);
    }
    return 0;
}
