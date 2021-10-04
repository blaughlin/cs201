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
        cout << "#################################" << endl;
        cout << "1: Create New Account" << endl;
        cout << "2: Deposit Money" << endl;
        cout << "3: Withdraw Money" << endl;
        cout << "4: Check Account Balance" << endl;
        cout << "5: Close Account" << endl;
        cout << "6: Account Info" << endl;
        cout << "7: Quit Program" << endl;
        cout << "#################################" << endl;
        cout << "Enter choice ";
        cin >> choice;
        while (!std::cin.good()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            cout << "Enter choice (1-7) ";
            cin >> choice;
        }
        switch (choice) {
            // create a new account
            case 1: {
                cout << "Please create an account name: ";
                cin >> accountKey;
                currentRecord.owner = accountKey;
                if (CreateRecord(accountKey, currentRecord) ) {
                   cout << "Account Created" << endl;
                } else {
                    cout << "Invalid input or you already have created an account." << endl;
                }
                break;
            }
            // Deposit Money
            case 2:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "Enter deposit amount: ";
                    cin >> deposit;
                    currentRecord.balance += deposit;
                    if (UpdateRecord(accountKey, currentRecord)) {
                        cout << "$" << deposit << " deposited.\n";
                    } else {
                        cout << "Error: Could not perform deposit." << endl;
                    }
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            // Withdraw Money
            case 3:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (ReadRecord(accountKey, currentRecord)) {
                    cout << "Enter amount to withdraw: ";
                    cin >> deposit;
                    currentRecord.balance -= deposit;
                    if (UpdateRecord(accountKey, currentRecord))
                    {
                        cout << "$" << deposit << " withdrawn.\n";
                    } else {
                        cout << "Error: Could not perform withdraw." << endl;
                    }
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            // Get Current Balance
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
            // Delete Account
            case 5:
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (DeleteRecord(accountKey)){
                    cout << "Account Deleted." << endl;
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            // Print out account details
            case 6:{
                cout << "Please enter account name: ";
                cin >> accountKey;
                if (PrintRecord(accountKey)) {
                    cout << "Thank you for banking with us." << endl;
                } else {
                    cout << "Account not found" << endl;
                }
                break;
            }
            // Quit Program
            case 7:
                isDone = true;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
    return 0;
}
