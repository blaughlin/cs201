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

vector<int> AskForGuess() {
    vector<int> guess;
    std::string input;
    int x;
    cout << "Please enter 4 numbers 0 to 9 or a negative number to quit: ";
    cin >> input;
    istringstream instream(input);
    instream >> x;
    if (!instream) {
        cout << "Invalid input, text needs to be a number" << endl;
    } else {
        for (auto i : input) {
            // if negative number found return negative -1
            if (i - '0' <= 0) {
                guess.push_back(-1);
                return guess;
            } else if (i <48 || i > 57 ) {
                guess.push_back(-2);
                cout << "Please only enter integers" << endl;
                return guess;
            }
            guess.push_back(i - '0');
        }
    }
    return guess;
}

int main() {
    bool gameOver = false;
    vector<int> key = GenerateRandomInts(4);
    vector<int> guess;
    for (auto i : key) {
        cout << i << endl;
    }
    while (!gameOver) {
        guess = AskForGuess();
        for (auto i : guess) {
            cout << i << endl;
            // end game if negative number found
            if (i == -1) {
                gameOver = true;
            // break out of for loop if person entered numbers followed by letters
            } else if ( i == -2 ){
                break;
            }
        }
    }

    return 0;
}
