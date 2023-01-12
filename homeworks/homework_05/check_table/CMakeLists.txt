cmake_minimum_required(VERSION 3.12)

project(table)

add_executable(table
    table.hpp
    table.cpp
)

set_target_properties(table PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)