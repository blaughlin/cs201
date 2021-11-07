// hangman.cpp
// Bernard Laughlin 11/4/2021
// Hangman game, player gets 10 trys to guess correct word

#include <iostream>
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
using std::for_each;
using std::find;
using std::getline;
using std::istringstream;
using std::set;

// Prints current correct guesses
void PrintCorrGuesses(vector<char> & results) {
    for_each(results.begin(), results.end(),
                  [](char i){ cout << i; });
    cout << endl;
}

// Gets and validates user input.
void GetInput(char & guess, vector<char> & results) {
    string input;
    while (true) {
        PrintCorrGuesses(results);
        cout << "Enter Your guess: ";
        getline(cin, input);
        istringstream istream(input);
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


// Checks to see if guess is correct
void CheckGuess(const char & guess, const string & key,  map<char,bool> & history,
                int & found, int & guessCount, vector<char> & results) {
    auto it = find(key.begin(), key.end(), guess);
    auto old = history.find(guess);
    if (it != key.end()) {
        results = {};
        // if letter never guessed before increase found count
        if (history.count(guess) == 0) found +=1;
        history[guess] = true;
        for_each(key.begin(), key.end(),
                      [&history, &results](char i){if (history.count(i)) {
                          results.push_back(i);
                      } else {
                          results.push_back('_');
                      }
        });
//        if (history.count(guess) == 0 ) {
//            found += 1;
//            cout << "FOUND " << found << endl;
//        }
        PrintHangman(guessCount);
    } else {
        guessCount++;
        PrintHangman(guessCount);
    }
}

// Ends game and prints a message if you won or loss the game.
void CheckIfWon(int & guessCount, const int & found, bool & gameOver, const string & answer,
                vector<char> results) {

    set<char> ans(answer.begin(), answer.end());
    cout << "SIZE: " << ans.size() << endl;
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
    cout << "WELCOME TO THE HANGMAN GAME!" << endl;
    // number of guesses attempted
    int guessCount = 0;
    // number of words found
    int found = 0;
    // keeps track of all letters guesses
    map<char, bool> guessed;
    // current guess
    char guess;
    bool gameOver = false;
    string answer("pineapple");
    // Display for letters found, set to all '_' at start
    vector<char> results(answer.size(), '_');

    while (!gameOver){
        GetInput(guess, results);
        CheckGuess(guess, answer, guessed, found, guessCount, results);
        CheckIfWon(guessCount, found, gameOver, answer, results);
        cout << endl;
    }

    return 0;
}
