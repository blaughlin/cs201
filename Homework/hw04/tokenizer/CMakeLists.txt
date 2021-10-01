cmake_minimum_required(VERSION 3.20)
project(tokenizer)

set(CMAKE_CXX_STANDARD 14)

add_executable(tokenizer tokenizertest.cpp tokenizer.cpp tokenizer.hpp)
