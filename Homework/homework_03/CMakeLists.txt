cmake_minimum_required(VERSION 3.12)

project(guess_number)

add_executable(guess_number
    guess_number.cpp
    guess_number.hpp
)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)