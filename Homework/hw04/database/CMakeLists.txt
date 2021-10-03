cmake_minimum_required(VERSION 3.20)
project(database)

set(CMAKE_CXX_STANDARD 20)

add_executable(database crud.cpp database.cpp database.hpp)
