// database.cpp
// Created by Bernard Laughlin on 10/3/21.
// CRUD functions

#include <map>
#include "database.hpp"
using std::cout;
using std::string;
using std::map;
using std::cin;
using std::endl;

map<string, BankAccount> accounts;

// Creates a new bank account and prompts for input, returns true if successfully created
bool CreateRecord(const std::string & key, BankAccount & record) {
    string name, type;
    double deposit;
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        name = record.owner;
        cout << "Enter 'checking' to open a checking account or 'saving' to open a saving account:  ";
        cin >> type;
        if (type != "checking" && type != "saving") {
            cout << "Invalid input. Can only open up a saving or checking account." << endl;
            return false;
        }
        cout << "How much money would you like to deposit in USD?  ";
        cin >> deposit;
        if (deposit <= 0) {
            cout << "Deposit must be greater than $0" << endl;
            return false;
        }
        BankAccount newAccount;
        accounts[key] = newAccount;
        accounts[name].accountType = type;
        accounts[name].balance = deposit;
        if (type == "checking") {
            accounts[name].interest = 0;
        } else {
            accounts[name].interest = 0.01;
        }
        return true;
    }
    return false;
}

// returns true if record id in accounts
bool ReadRecord(const std::string & key, BankAccount & record){
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        return false;
    }
    record = it->second;
    return true;
}

// returns true if record updated
bool UpdateRecord(const std::string & key, const BankAccount & record){
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        return false;
    }
    accounts[key] = record;
    return true;
}

// returns true if record deleted
bool DeleteRecord(const std::string & key){
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        return false;
    }
    accounts.erase(key);
    return true;
}

// returns true if record found and prints account information
bool PrintRecord(const std::string & key){
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        return false;
    }
    cout << "Account type: " << accounts[key].accountType << endl;
    cout << "Account balance $" << accounts[key].balance << endl;
    cout << "Interest rate: " << accounts[key].interest << "%" << endl;
    return true;
}