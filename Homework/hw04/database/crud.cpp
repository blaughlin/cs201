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
    double deposit;
    string accountKey;
    BankAccount currentRecord;
    while (!isDone) {
        cout << "1: Create New Account" << endl;
        cout << "2: Deposit Money" << endl;
        cout << "3: Withdraw Money" << endl;
        cout << "4: Check Account Balance" << endl;
        cout << "5: Close Account" << endl;
        cout << "6: Account Info" << endl;
        cout << "7: Quit Program" << endl;
        cout << "Enter choice ";
        cin >> choice;
        switch (choice) {
            case 1:
                InputRecord(currentRecord);
                break;
            case 2:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "Enter deposit amount: ";
                    cin >> deposit;
                    currentRecord.balance += deposit;
                    if (UpdateRecord(accountKey, currentRecord)) cout << "$" << deposit << " deposited.\n";
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            case 3:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "Enter amount to withdraw: ";
                    cin >> deposit;
                    currentRecord.balance -= deposit;
                    if (UpdateRecord(accountKey, currentRecord)) cout << "$" << deposit << " withdrawn.\n";
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            case 4: {
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
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (DeleteRecord(accountKey)){
                    cout << "Account Deleted." << endl;
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            case 6:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "Account type: " << currentRecord.accountType << endl;
                    cout << "Account balance $" << currentRecord.balance << endl;
                    cout << "Interest rate: " << currentRecord.interest << "%" << endl;
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            case 7:
                isDone = true;
                break;
            default:
                cout << "Invalid input.";
                break;
        }
    }

    return 0;
}
