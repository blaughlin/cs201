// crud.hpp
// Bernard Laughlin 10/3/2021
// CRUD checking account application

#include <iostream>
#include <string>
#include "database.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int choice;
    bool isDone = false;
    BankAccount currentRecord;
    while (!isDone) {
        cout << "1: Create New Account" << endl;
        cout << "2: Deposit Money" << endl;
        cout << "3: Withdraw Money" << endl;
        cout << "4: Check Account Balance" << endl;
        cout << "5: Close Account" << endl;
        cout << "6: Quit Program" << endl;
        cout << "Enter choice ";
        cin >> choice;
        switch (choice) {
            case 1:
                InputRecord(currentRecord);
                break;
            case 2:
                cout << "coming soon" << endl;
                break;
            case 3:
                cout << "coming soon" << endl;
                break;
            case 4: {
                string accountKey;
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "$" << currentRecord.balance << endl;
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            case 5:
                cout << "coming soon" << endl;
                break;
            case 6:
                isDone = true;
                break;
            default:
                cout << "Invalid input.";
                break;
        }
    }

    return 0;
}
