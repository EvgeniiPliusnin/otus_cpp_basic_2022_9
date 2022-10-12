cmake_minimum_required(VERSION 3.12)

project(02.hello_world)

add_executable(hello_world 
    hello_world.cpp
    example.cpp
    example.h
    lib_move_todo/move_me_out.cpp
    lib_move_todo/move_me_out.h
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
