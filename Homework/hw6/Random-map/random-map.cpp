// random-map.cpp
// Bernard Laughlin 11/2/2021
// Tests na uniform and normal random distribution of numbers

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::endl;


// Generates a uniform random number between first and last inclusive
int RandomBetweenU(int first, int last) {
    std::random_device rd;
    std::uniform_int_distribution<int> uniform_dist(first, last);
    return uniform_dist(rd);
}

// Generates a normally distributed random number between first and last inclusive
int RandomBetweenN(int first, int last) {
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);

    // Generate a normal distribution around that mean
    std::mt19937 e2(r());
    std::normal_distribution<> normal_dist(mean, 2);
    int normalNumber;

    // Endure number is between first and last values
    while(true){
        normalNumber = std::round(normal_dist(e2));
        if (normalNumber <= last && normalNumber >= first) break;
    }
    return normalNumber;
}

// Generates a random number between first and last inclusive via rand()
int RandomBetween(int first, int last) {
    return (std::rand() % (last + 1 - (first)) + first);
}

// Prints distribution
void PrintDistribution(const std::map<int, int> & numbers) {
    for (auto p : numbers) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/100, '*') << '\n';
    }
}

int main() {
    std::map<int, int> histN;
    for (int n = 0; n < 10000; ++n) {
        ++histN[RandomBetweenN(1,7)];
    }
    cout << "Normal distribution" << endl;
    PrintDistribution(histN);

    std::map<int, int> histU;
    for (int n = 0; n < 10000; ++n) {
        ++histU[RandomBetweenU(1,7)];
    }
    cout << "Uniform distribution" << endl;
    PrintDistribution(histU);

    std::map<int, int> histR;
    for (int n = 0; n < 10000; ++n) {
        ++histR[RandomBetween(1,7)];
    }
    cout << "Random distribution using rand()" << endl;
    PrintDistribution(histR);

    return 0;
}
