/*
greatest.cpp
Bernard Laughlin
9/2/2021
Assignment for cs201 that returns the greatest positive number
*/

#include <iostream>

using std::cout;
using std::cin;

    int main() {
    int max = -1;
    int x;
    std::cout << "Enter a sequence of positive integers, ending with zero.\n";
    std:cout << "I will print the greatest positive number entered.\n";
    std::cout << "Enter a positive integer (0 to end): ";
    while (std::cin >> x) {
        if ( x <= 0 ) {
            if (max == -1){
                std::cout << "No positive integers were entered.\n";
            }
            break;
        } else {
            std::cout << "Enter a positive integer (0 to end): ";
            if (x > max) {
                max = x;
            }
        }
    }
    if (max > 0) {
        std::cout << "The greatest number entered: " << max << "\n";
    }
}
