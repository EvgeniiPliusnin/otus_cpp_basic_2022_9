cmake_minimum_required(VERSION 3.12)

project(my_example)

find_package( Boost 1.74 COMPONENTS program_options REQUIRED )

add_executable(my_example
    main.cpp
)

target_link_libraries(my_example Boost::program_options)

set_target_properties(my_example PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

