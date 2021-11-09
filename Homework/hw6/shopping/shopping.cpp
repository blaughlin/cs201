// shopping.cpp
// Bernard Laughlin 11/8/2021
// cs201 homework assignment to create a program to represent a storefront.

#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::istringstream;

struct Record {
    string name;
    double unitPrice;
    int units;
    int upc;
};

// Prints menu options and prompts user for selection and returns int selected
int GetInput(){
    int choice;
    string input;
    while (true){
        cout << "**************************************************" << endl;
        cout << "* 1. List items in shopping cart.                *" << endl;
        cout << "* 2. Calculate total cost in shopping cart.      *" << endl;
        cout << "* 3. Add item to shopping cart.                  *" << endl;
        cout << "* 4. Remove item from shopping cart.             *" << endl;
        cout << "* 5. Quit.                                       *" << endl;
        cout << "**************************************************" << endl;
        cout << "Please make a selection: ";
        getline(cin, input);
        istringstream istream(input);
        istream >> choice;
        if (!istream) cout << "Invalid input. Please try again." << endl;
        if (choice >= 1 && choice <= 5) break;
        cout << "Please enter a number between 1 and 5." << endl;
    }
    return choice;
}
int main() {
    int selection = GetInput();
    return 0;
}
