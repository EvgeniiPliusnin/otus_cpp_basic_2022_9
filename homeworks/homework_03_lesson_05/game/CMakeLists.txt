cmake_minimum_required(VERSION 3.12)

project(guess_number)

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)
find_package(Chrono COMPONENTS Irrlicht CONFIG)

add_executable(${PROJECT_NAME}
        src/game.cppF
        include/table.hpp
        src/table.cpp
        include/structures.hpp
        src/timer.cpp
        include/timer.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

target_link_libraries(${PROJECT_NAME} Boost::program_options)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)