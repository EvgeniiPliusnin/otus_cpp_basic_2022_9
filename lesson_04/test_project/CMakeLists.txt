cmake_minimum_required(VERSION 3.12)

project(04.fib)

add_executable(fib
    fib.cpp
)

set_target_properties(fib
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)