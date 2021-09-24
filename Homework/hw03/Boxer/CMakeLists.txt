cmake_minimum_required(VERSION 3.20)
project(Boxer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Boxer boxprint.cpp boxer.cpp boxer.hpp)
