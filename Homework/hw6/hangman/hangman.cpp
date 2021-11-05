// hangman.cpp
// Bernard Laughlin 11/4/2021
// Hangman game, player gets 10 trys to guess correct word

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::map;


// Gets and validates user input.
void getInput(char & guess) {
    string input;
    while (true) {
        cout << "Enter Your guess: ";
        std::getline(cin, input);
        std::istringstream istream(input);
        istream >> guess;
        if (!istream) cout << "Invalid input." << endl;
        if (input.length() > 1) {
            cout << "Please only guess one letter." << endl;
        } else break;
    break;
    }
}


void checkGuess(const char & guess, const string & key,  map<char,bool> & history, int & found) {
    auto it = std::find(key.begin(), key.end(), guess);
    auto old = history.find(guess);

    if (it != key.end() && !history.count(guess)) {
        cout << "found it" << endl;
        history[guess] = true;
        std::for_each(key.begin(), key.end(),
                      [&history](char i){if (history.count(i)) {
                          cout << i;
                      } else cout << " ";});
        found += 1;
    } else cout << "Letter not found." << endl;
}


int main() {
    int guessCount = 0;
    int found = 0;
    map<char, bool> guessed;
    char guess;
    bool gameOver = false;
    string answer("look");
    std::set<char>  ans(answer.begin(), answer.end());

    while (!gameOver){
        getInput(guess);
        guessCount++;
        checkGuess(guess, answer, guessed, found);
        if (found == ans.size()) {
            cout << endl << "You Won!" << endl;
            gameOver = true;
        }
        if (guessCount == 3) {
            cout << "GAME OVER!" << endl;
            gameOver = true;
        }
        cout << endl;
    }

    return 0;
}
