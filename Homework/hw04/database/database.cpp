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

bool CreateRecord(const std::string & key) {
    BankAccount newAccount;
    accounts[key] = newAccount;
    return true;
}

bool ReadRecord(const std::string & key, BankAccount & record){
    auto it = accounts.find(key);
    if (it == accounts.end()) {
        return false;
    }
    record = it->second;
    return true;
}

bool UpdateRecord(const std::string & key, const BankAccount & record){

}

bool DeleteRecord(const std::string & key){

}

bool InputRecord(BankAccount & record){
    string name, type;
    double deposit;

    cout << "Enter your name:  ";
    cin >> name;
    cout << "Enter 'checking' to open a checking account or 'saving' to open a saving account:  ";
    cin >> type;
    cout << "How much money would you like to deposit in USD?  ";
    cin >> deposit;
    CreateRecord(name);
    accounts[name].owner = name;
    accounts[name].accountType = type;
    accounts[name].balance = deposit;
    return true;
}

bool PrintRecord(const std::string & key){

}