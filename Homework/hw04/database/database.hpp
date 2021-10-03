// database.hpp
// Created by Bernard Laughlin on 10/3/21.
// Header for database.cpp

#include <iostream>
#include <string>

#ifndef DATABASE_DATABASE_HPP
#define DATABASE_DATABASE_HPP

struct BankAccount {
    std::string accountType;
    std::string owner;
    double interest;
    double balance;
};

bool CreateRecord(const std::string & key);
bool ReadRecord(const std::string & key, BankAccount & record);
bool UpdateRecord(const std::string & key, const BankAccount & record);
bool DeleteRecord(const std::string & key);
bool InputRecord(BankAccount & record);
bool PrintRecord(const std::string & key);
#endif //DATABASE_DATABASE_HPP
