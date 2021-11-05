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

// Prints current correct guesses
void PrintCorrGuesses(vector<char> & results) {
    std::for_each(results.begin(), results.end(),
                  [](char i){ cout << i; });
    cout << endl;
}

// Gets and validates user input.
void getInput(char & guess, vector<char> & results) {
    string input;
    while (true) {
        PrintCorrGuesses(results);
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


// Prints the hangman based on number of guesses.
void PrintHangman(const int & guessCount) {
    switch (guessCount) {
        case 1:
            cout << "  0  " << endl;
            break;
        case 2:
            cout << "  0  " << endl;
            cout << "  |  " << endl;
            break;
        case 3:
            cout << "  0  " << endl;
            cout << " -|  " << endl;
            break;
        case 4:
            cout << "  0  " << endl;
            cout << " -|-  " << endl;
            break;
        case 5:
            cout << "  0  " << endl;
            cout << " -|- " << endl;
            cout << " /   " << endl;
            break;
        case 6:
            cout << "  0  " << endl;
            cout << " -|- " << endl;
            cout << " / \\  " << endl;
            break;
        case 7:
            cout << "  0  " << endl;
            cout << "+-|- " << endl;
            cout << " / \\  " << endl;
            break;
        case 8:
            cout << "  0  " << endl;
            cout << "+-|-+" << endl;
            cout << " / \\  " << endl;
            break;
        case 9:
            cout << "  0  " << endl;
            cout << "+-|-+" << endl;
            cout << "_/ \\  " << endl;
            break;
        case 10:
            cout << "  0  " << endl;
            cout << "+-|-+" << endl;
            cout << "_/ \\_  " << endl;
            break;
        default:
            cout << " " << endl;
    }
}


// Checks to see oif guess is correct
void checkGuess(const char & guess, const string & key,  map<char,bool> & history,
                int & found, int & guessCount, vector<char> & results) {
    auto it = std::find(key.begin(), key.end(), guess);
    auto old = history.find(guess);

    if (it != key.end() && !history.count(guess)) {
        results = {};
        history[guess] = true;
        std::for_each(key.begin(), key.end(),
                      [&history, &results](char i){if (history.count(i)) {
                          results.push_back(i);
                      } else {
                          results.push_back('_');
                      }
        });
        found += 1;
        PrintHangman(guessCount);
    } else {
        guessCount++;
        PrintHangman(guessCount);
    }
}

// Ends game and prints a message if you won or loss the game.
void checkIfWon(int & guessCount, const int & found, bool & gameOver, const string & answer,
                vector<char> results) {

    std::set<char>  ans(answer.begin(), answer.end());
    if (found == ans.size()) {
        PrintCorrGuesses(results);
        cout << endl << "You Won!" << endl;
        gameOver = true;
    }
    if (guessCount == 10) {
        cout << "GAME OVER!" << endl;
        gameOver = true;
    }
}

int main() {
    int guessCount = 0;
    int found = 0;
    map<char, bool> guessed;
    char guess;
    bool gameOver = false;
    vector<char> results = {'_','_', '_', '_'};
    string answer("look");

    while (!gameOver){
        getInput(guess, results);
        checkGuess(guess, answer, guessed, found, guessCount, results);
        checkIfWon(guessCount, found, gameOver, answer, results);
        cout << endl;
    }

    return 0;
}
