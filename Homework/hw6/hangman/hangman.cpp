// hangman.cpp
// Bernard Laughlin 11/4/2021
// Hangman game, player gets 10 trys to guess correct word

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

// Gets and validates user input.
void getInput(string & guess) {
    string input;
    while (true) {
        cout << "Enter Your guess: ";
        std::getline(cin, input);
        std::istringstream istream(input);
        istream >> guess;
        if (!istream) cout << "Invalid input." << endl;
        if (guess.length() > 1) {
            cout << "Please only guess one letter." << endl;
        } else break;
    }
}


int main() {
    string guess;
    bool gameOver = false;
    string answer = "Kangaroo";
    while (!gameOver){
        getInput(guess);
        if (guess == answer) gameOver = true;
        cout << "you guessed: " << guess << std::endl;
    }
    return 0;
}
