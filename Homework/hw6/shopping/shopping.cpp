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
#include <map>
using std::map;
#include <iomanip>
using std::setw;
using std::left;

struct Record {
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

// Prints header for shopping cart and store inventory
void PrintHeader() {
    cout << "_____________________________________________" << endl;
    cout << left << setw(10) << "Units";
    cout << left << setw(25) << "Product";
    cout << left << setw(10) << "Unit Price" << endl;
    cout << "----------------------------------------------" << endl;
}

// Prints store inventory and items in shopping cart
void PrintCart(const map<std::string,Record> & cart) {
    PrintHeader();
    for (auto item : cart){
        cout << left << setw(10) << item.second.units <<
        left << setw(25) << item.first <<
        left << setw(1) << " $" << setw(12)<< item.second.unitPrice << endl;
    }
}

//void AddItem(map<string, Record> & item, map<string, Record> & cart) {
//
//}

int main() {
    map<string, Record> cart = {};
    map<string, Record> products = {};
    products["Gallon of milk"] = {2.99, 10, 5555};
    products["Carton of eggs"] = {1.99, 5, 4444};
    products["Bag of coffee beans"] = {13.99, 20, 1111};
    products["1lb package of Bacon"] = {5.99, 15, 3333};
    products["5lb bag of Flour"] = {2.49, 14, 7777};
    PrintCart(products);
//    int selection = GetInput();
    return 0;
}
