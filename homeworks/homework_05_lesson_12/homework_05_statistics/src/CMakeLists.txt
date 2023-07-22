cmake_minimum_required(VERSION 3.5)

project(statistics)

add_executable(${PROJECT_NAME}
        main.cpp
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../statistics_lib/include)

target_link_libraries(${PROJECT_NAME} statistics_library)
