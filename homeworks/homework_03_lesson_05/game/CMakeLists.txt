cmake_minimum_required(VERSION 3.12)

project(guess_number)

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)
find_package(Chrono COMPONENTS Irrlicht CONFIG)

add_executable(guess_number
    game.cpp
    table.hpp
    table.cpp
    structures.hpp    
)

target_link_libraries(guess_number Boost::program_options)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)