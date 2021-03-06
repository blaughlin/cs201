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
#include <time.h>

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
    std::random_device rd;
    std::default_random_engine generator;
    std::normal_distribution<int> normal_dist(first,last);
    return normal_dist(generator);
}

// Generates a random number between first and last inclusive via rand()
int RandomBetween(int first, int last) {
   std::srand(time(NULL));
    return first + (std::rand() % last);
}

int main() {
//    // Seed with a real random value, if available
//    std::random_device r;
//
//    // Choose a random mean between 1 and 6
//    std::default_random_engine e1(r());
//    std::uniform_int_distribution<int> uniform_dist(1, 6);
//    int mean = uniform_dist(e1);
//    std::cout << "Randomly-chosen mean: " << mean << '\n';
//
//    // Generate a normal distribution around that mean
//    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
//    std::mt19937 e2(seed2);
//    std::normal_distribution<> normal_dist(mean, 2);
//
//    std::map<int, int> hist;
//    for (int n = 0; n < 10000; ++n) {
//        ++hist[std::round(normal_dist(e2))];
//    }
//    std::cout << "Normal distribution around " << mean << ":\n";
//    for (auto p : hist) {
//        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
//                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
//    }
    cout << RandomBetweenU(1,10) << endl;
    cout << RandomBetweenN(1,100) << endl;
    cout << RandomBetween(1,5) << endl;
    return 0;
}
