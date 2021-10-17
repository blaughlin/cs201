// main.cpp
// Bernard Laughlin 10/13/2021
// Midterm exam for cs201

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Question 4
// Returns to sum of all elements in the vector named container
double SumVector(std::vector<float> container) {
    float sum = 0.0;
    for (auto value : container) {
        sum += value;
    }
    return sum;
}

// Question 5
// Returns true if int vector named container is sorted
bool isSorted(std::vector<int> container){
    for (int i = 0; i < container.size() - 1; i++){
        if (container[i] > container[i+1]) return false;
    }
    return true;
}

// Question 7
// Prints out all substrings in string
void PrintSubstrings(std::string s) {
    for (int i = 0; i < s.size(); i++){
        for(int j = 1; j <= s.size() - i; j++){
            std::cout << s.substr(i,j) << std::endl;
        }
    }
}

// Question 8
// Reads in and returns an integer that is not below or above specified min or max value
int ReadInt(std::string prompt, int min, int max){
    int value;
    std::string input;
    while (true){
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream istream(input);
        istream >> value;
        if (!istream) std::cout << "Invalid input." << std::endl;
        if (value <= max && value >= min) {
            break;
        }
    }
    return value;
}

int main() {
    std::cout << "Question 4 output." << std::endl;
    std::vector<float> container = {0.1, -0.1, 5.5, 1.5};
    std::cout << SumVector(container) << std::endl;

    std::cout << "Question 5 output." << std::endl;
    std::vector<int> a = {-1,4,123};
    std::vector<int> b = {1,2,7,4,5};
    std::cout << isSorted(a) << std::endl;
    std::cout << isSorted(b) << std::endl;

    std::cout << "Question 7 output." << std::endl;
    std::string c = "abcd";
    PrintSubstrings(c);

    std::cout << "Question 8 output." << std::endl;
    int ans = ReadInt("Enter a number between 1 and 10 ", 1,10);
    std::cout << "You entered: " << ans << std::endl;

    return 0;
}
