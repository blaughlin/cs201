/*
money.cpp
Bernard Laughlin
9/14/2021
Prompts users to enter coins they have and tell them the number of pennies, nickels, dimes, 
quarters, half dollars and value of all coins.
*/

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int pennies;
    int nickles;
    int dimes;
    int quarters;

    int dollars;
    float total;

    std::cout << "Enter number of pennies: ";
    std::cin >> pennies;
    while (pennies < 0){
        std::cout << "You need to enter a positive number\n";
        std::cout << "Enter number of pennies: ";
        std::cin >> pennies;
    }
    total = pennies;

    std::cout << "Enter number of nickles: ";
    std::cin >> nickles;
    while (nickles < 0)
    {
        std::cout << "You need to enter a positive number\n";
        std::cout << "Enter number of nickles: ";
        std::cin >> nickles;
    }
    total += nickles * 5;

    std::cout << "Enter number of dimes: ";
    std::cin >> dimes;
    while (dimes < 0)
    {
        std::cout << "You need to enter a positive number\n";
        std::cout << "Enter number of dimes: ";
        std::cin >> dimes;
    }
    total += dimes * 10;

    std::cout << "Enter number of quarters: ";
    std::cin >> quarters;
    while (quarters < 0)
    {
        std::cout << "You need to enter a positive number\n";
        std::cout << "Enter number of quarters: ";
        std::cin >> quarters;
    }
    total += quarters * 25;

    std::cout << "Enter number of one dollar coins: ";
    std::cin >> dollars;
    while (dollars < 0)
    {
        std::cout << "You need to enter a positive number\n";
        std::cout << "Enter number of dollar coins: ";
        std::cin >> dollars;
    }
    total += dollars * 100;

    if (pennies > 1) {
            std::cout << "You have " << pennies << " pennies.\n";
    } else {
        std::cout << "You have " << pennies << " penny.\n";
    }
    if (nickles > 1) {
        std::cout << "You have " << nickles << " nickels.\n";
    } else {
        std::cout << "You have " << nickles << " nickel.\n";
    }
    if (dimes > 1) {
        std::cout << "You have " << dimes << " dimes.\n";
    } else {
        std::cout << "You have " << dimes << " dime.\n";
    }
    if (quarters > 1) {
        std::cout << "You have " << quarters << " quarters.\n";
    } else {
        std::cout << "You have " << quarters << " quarter.\n";
    }

    if (dollars > 1) {
        std::cout << "You have " << dollars << "  dollar-coins.\n";
    } else {
        std::cout << "You have " << dollars << " dollar-coin.\n";
    }   

    std::cout << "The value of all your coins is " << total << " cents.\n";
    std::cout << "The value of all your coins is $" << total/100 << "\n";
}
