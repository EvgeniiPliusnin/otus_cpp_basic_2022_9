cmake_minimum_required(VERSION 3.12)

project(statistics_library)

set(HEADERS
        include/statistics.hpp
        include/max.hpp
        include/min.hpp
        include/mean.hpp
        include/sd.hpp
        include/pct.hpp
)

set(SOURCES
        src/min.cpp
        src/max.cpp
        src/mean.cpp
        src/sd.cpp
        src/pct.cpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

include_directories(include)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)