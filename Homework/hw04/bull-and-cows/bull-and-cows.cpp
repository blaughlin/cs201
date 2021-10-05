#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

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

int main() {
    vector<int> key = GenerateRandomInts(4);

    for (auto i : key) {
        cout << i << endl;
    }
    return 0;
}
