`// quadratic.cpp
// Bernard Laughlin 9-28-2021
// quadratic homework assignment for cs201
// computes roots of quadratic equation

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// ensures we don't try to compute a negative square root
bool possibleRoot(double a, double b, double c) {
    if (b * b -(4 * a * c) >= 0) {
        return true;
    }
    return false;
}

int main() {
    double a, b, c;
    cout << "Solve quadratic equation" << endl;
    cout << "Enter the following coefficients (a, b, c) each followed by a space:  " ;
    cin >> a >> b >> c;
    while (!std::cin.good()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        cout << "Enter the following coefficients (a, b, c) each followed by a space:  ";
        cin >> a >> b >> c;
    }
    if (possibleRoot(a, b,c )){
        double ans1 = ( -b + sqrt(b * b - (4 * a * c)) ) / ( 2 * a );
        double ans2 = ( -b - sqrt(b * b - (4 * a * c)) ) / ( 2 * a );
        if (ans1 == ans2){
            cout << "The root is " << ans1 << endl;
        } else {
            cout << "The roots are " << ans1 << " and " << ans2 << endl;
        }
    } else {
        cout << "sorry no solution is possible based on those coefficients" << endl;
    }
    return 0;

}

// could use testing to insure results are correct`