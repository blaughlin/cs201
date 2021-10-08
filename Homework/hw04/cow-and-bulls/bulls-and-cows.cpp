// bulls-and-cows.cpp
// Bernard Laughlin 10/8/2021
// Guessing game for cs201

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include  <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istringstream;


// Generates unique random numbers in the range 0 to 9 for game
vector<int> GenerateRandomInts(int amount) {
    vector<int> numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,9);

    // set limit on size of vector to ensure we don't end up in an endless loop
    if (amount > 10) {
        amount =10;
    }
    while (true) {
        if (numbers.size() == amount) {
            break;
        }
        int randomNumber = distrib(gen);
        if (std::find(numbers.begin(), numbers.end(), randomNumber) == numbers.end()){
            numbers.push_back(randomNumber);
        }
    }
    return numbers;
}

// Prompts user for guess it appends negative 1 to return vector if a negative number
// is found or negative 2 if invalid input.
vector<int> AskForGuess() {
    vector<int> guess;
    std::string input;
    int x;
    cout << "Please enter 4 unique numbers from 0 to 9 or a negative number to quit: ";
    cin >> input;
    istringstream instream(input);
    instream >> x;
    if (!instream) {
        cout << "Invalid input, text needs to be a number" << endl;
        guess.push_back(-2);
        return guess;
    } else {
        for (auto i : input) {
            // if negative number found return negative -1
            if (i - '0' < 0) {
                guess.push_back(-1);
                return guess;
                // if there is text followed entered after an integer
            } else if (i <48 || i > 57 ) {
                guess.push_back(-2);
                cout << "Please only enter integers" << endl;
                return guess;
                // if user entered same number again
            } else if (std::find(guess.begin(), guess.end(), i - '0') != guess.end()) {
                guess.push_back(-2);
                cout << "Please only enter unique integers" << endl;
                return guess;
            }
            guess.push_back(i - '0');
        }
    }
    return guess;
}

// Returns the number of correctly match guesses
int CheckForBulls(vector<int> key, vector<int> guess) {
    int bulls = 0;
    for (auto i = 0; i < key.size(); i++){
        if (key[i] == guess[i]) {
            bulls += 1;
        }
    }
    return bulls;
}

int CheckForCows(vector<int> key, vector<int> guess) {
    int cows = 0;
    int bulls = CheckForBulls(key, guess);
    for (auto i : guess) {
        if ( std::find(key.begin(), key.end(), i) != key.end()) {
            cows += 1;
        }
    }
    return cows - bulls;
}

// Main game loop
int main() {
    bool isInvalid = false;
    bool gameOver = false;
    int bulls = 0;
    int cows = 0;
    std::string bullStr = " bull ";
    std::string cowStr = " cow";
    vector<int> key = GenerateRandomInts(4);
    vector<int> guess;
    while (!gameOver) {
        isInvalid = false;
        guess = AskForGuess();
        for (auto i : guess) {
            // end game if negative number found and print answer
            if (i == -1) {
                cout << i << endl;
                gameOver = true;
                cout << "Answer was: ";
                for (auto j : key) {
                    cout << j;
                }
                // break out of for loop if input invalid
            } else if (i == -2) {
                isInvalid = true;
                break;
            }
        }
        // Print out guess
        if (!isInvalid && !gameOver) {
            cout << "You guessed: ";
            for (auto i : guess){
                cout << i;
            }
            // Print out bulls and cows
            cout << endl;
            bulls = CheckForBulls(key, guess);
            cows = CheckForCows(key, guess);
            if (bulls > 1 ) bullStr = " bulls ";
            if (cows > 1 ) cowStr = " cows";
            cout << bulls  << bullStr << cows << cowStr << endl;
            // Check if player won
            if (bulls == 4) {
                cout << "You Won!" << endl;
                gameOver = true;
            }
        }
    }
    return 0;
}
