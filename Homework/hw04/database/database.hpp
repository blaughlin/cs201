// database.hpp
// Created by Bernard Laughlin on 10/3/21.
// Header for database.cpp

#include <iostream>
#include <string>
#ifndef DATABASE_DATABASE_HPP
#define DATABASE_DATABASE_HPP
struct CheckingAccount {
    std::string name;
    double balance;
};
bool CreateRecord(const std::string & key);
bool ReadRecord(const std::string & key, CheckingAccount & record);
bool UpdateRecord(const std::string & key, const CheckingAccount & record);
bool DeleteRecord(const std::string & key);
#endif //DATABASE_DATABASE_HPP
