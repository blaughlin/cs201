// collatz.cpp
// Bernard Laughlin 9/26/2021
// implements the collatz function [L. Collatz 1937]

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// returns true if input is odd
bool IsOdd(int n){
    return (n % 2 != 0);
}

// Prints int without a comma if input is one, else prints with a comma
void PrintResults(int input) {
    if (input == 1) {
        cout << input;
    } else {
        cout << input << ", ";
    }
}

int main() {
    int result;
    cout << "Input a positive integer: ";
    cin >> result;
    while (result <= 0 || std::isdigit(result)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Input a positive integer: ";
        cin >> result;
    }
    PrintResults(result);
    while (result != 1) {
        if (IsOdd(result)) {
            result = 3 * result + 1;
        } else {
            result = result / 2;
        }
        PrintResults(result);
    }
    return 0;
}