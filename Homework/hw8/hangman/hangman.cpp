// hangman.cpp
// Bernard Laughlin 11/4/2021
// Hangman game, player gets 10 trys to guess correct word

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <random>

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
using std::shuffle;
using std::random_device;
using std::mt19937;

class Hangman {
public:
    Hangman() {
        SelectDifficultyLevel();
        SetAnswer();
        for(auto i = 0; i < _answer.size(); i++) {
            _results.push_back('_');
        }
    }

    // Selects game difficulty level
    void SelectDifficultyLevel() {
        cout << "WELCOME TO THE HANGMAN GAME!" << endl;
        cout << "********************************" << endl;
        cout << "* WELCOME TO THE HANGMAN GAME! *" << endl;
        cout << "*                              *" << endl;
        cout << "* 1. Easy                      *" << endl;
        cout << "* 2. Medium                    *" << endl;
        cout << "* 3. Hard                      *" << endl;
        cout << "*                              *" << endl;
        cout << "********************************" << endl;
        string input;
        while (true) {
            cout << "Enter difficulty level: ";
            getline(cin, input);
            istringstream istream(input);
            istream >> _level;
            if (!istream) {
                cout << "Invalid input." << endl;
            } else  if (_level < 1 || _level > 3) {
                cout << "Enter a number between 1 and 3." << endl;
            } else  break;

        }
    }

    // Sets a random answer based on difficulty level
    void SetAnswer(){
        random_device rd;
        std::mt19937  gen(rd());
        if (_level == 1) {
            shuffle(begin(_easyWords), end(_easyWords), gen);
            _answer = _easyWords[0];
        } else if (_level == 2 ) {
            shuffle(begin(_mediumWords), end(_mediumWords), gen);
            _answer = _mediumWords[0];
        } else {
            shuffle(begin(_hardWords), end(_hardWords), gen);
            _answer = _hardWords[0];
        }
    }
    // Prints current correct guesses
    void PrintCorrGuesses() {
        for_each(_results.begin(), _results.end(),
                 [](char i){ cout << i; });
        cout << endl;
    }

    // Gets and validates user input.
    void GetInput() {
        string input;
        while (true) {
            PrintCorrGuesses();
            cout << "Enter Your guess: ";
            getline(cin, input);
            istringstream istream(input);
            istream >> _guess;
            if (!istream) cout << "Invalid input." << endl;
            if (input.length() > 1) {
                cout << "Please only guess one letter." << endl;
            } else break;
            break;
        }
    }

    // Prints the hangman based on number of guesses.
    void PrintHangman() {
        switch (_guessCount) {
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
    void CheckGuess() {
        auto it = find(_answer.begin(), _answer.end(), _guess);
        auto old = _guessed.find(_guess);
        if (it != _answer.end()) {
            _results = {};
            // if letter never guessed before increase found count
            if (_guessed.count(_guess) == 0) _found +=1;
            _guessed[_guess] = true;
            for_each(_answer.begin(), _answer.end(),
                     [this](char i){if (_guessed.count(i)) {
                         _results.push_back(i);
                     } else {
                        _results.push_back('_');
                     }
                     });
            PrintHangman();
        } else {
            _guessCount++;
            PrintHangman();
        }
    }

    // Ends game and prints a message if you won or loss the game.
    void CheckIfWon() {
        set<char> ans(_answer.begin(), _answer.end());
        if (_found == ans.size()) {
            PrintCorrGuesses();
            cout << endl << "You Won!" << endl;
            _gameOver = true;
        }
        if (_guessCount == 10) {
            cout << "GAME OVER!" << endl;
            cout << "Word was: " << _answer << endl;
            _gameOver = true;
        }
    }

    bool getGameOver() {
        return _gameOver;
    }


private:
    // number of guesses attempted
    int _guessCount = 0;
    // number of words found
    int _found = 0;
    // keeps track of all letters guesses
    map<char, bool> _guessed;
    // user's current guessed letter
    char _guess;
    // keeps track of  when game is over
    bool _gameOver = false;
    // difficulty level of game
    int _level;
    // Easy level words
    vector<string> _easyWords {"apple", "orange", "horse", "summer", "winter", "pineapple"};
    vector<string> _mediumWords {"academic", "covid", "regurgitation", "coup", "filibuster"};
    vector<string> _hardWords {"epistaxis", "juxtaposition", "quixotic", "baccalaureate", "extemporaneous"};
    // Answer to hangman game
    string _answer;
    // Current correct guesses
    vector<char> _results;

};


int main() {
    Hangman hm;
    bool gameOver = false;
    while (!gameOver){
        hm.GetInput();
        hm.CheckGuess();
        hm.CheckIfWon();
        gameOver = hm.getGameOver();
    }
    return 0;
}