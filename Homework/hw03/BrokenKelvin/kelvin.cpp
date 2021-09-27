// kelvin.cpp
// Bernard Laughlin 9-26-2021
// Converts celsius into kelvin
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// Converts Celsius to Kelvin
double CelsiusToKelvin(double c){
    return c + 273.15;
}

int main() {
    double celsius;
    cout << "Enter Celsius value to convert to Kelvin: ";
    cin >> celsius;
    while (!std::cin.good()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        cout << "Enter Celsius value to convert to Kelvin: ";
        cin >> celsius;
    }
    if (celsius < 273.15) {
        cout << "Error: temperature is below absolute zero." << endl;
    }
    cout << celsius;
    return 0;
}

// Error in original code
// 1. ctok declares an int k instead of a double
// 2. ctok function returns an int type instead of a variable
// 3. ctok is all lowercase functions should start with a capital letter.
// 4. a double c is declared but never used
// 5. cin trys to assign an input value to an undeclared variable d
// 6. ctok passes a character as a parameter instead of an int.