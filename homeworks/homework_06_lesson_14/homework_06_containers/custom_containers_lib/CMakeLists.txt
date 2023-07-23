cmake_minimum_required(VERSION 3.12)

project(custom_containers_lib)

include_directories(include)

set(HEADERS
        include/test.hpp
)

set(SOURCES
        src/test.cpp
)

add_library(${PROJECT_NAME} STATIC ${HEADER} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

find_path(CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS
        NAMES test.hpp
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}
        PATH_SUFFIXES include
)
