cmake_minimum_required(VERSION 3.12)

project(test_containers)

find_package(GTest)

add_executable(${PROJECT_NAME}
    double_linked_list_tests.cpp
    sequence_container_tests.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS})

# Add googletest to the include directories for the test target
target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${GTEST_INCLUDE_DIRS}
)

# Link test target against gtest libraries
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        ${GTEST_BOTH_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(
            ${PROJECT_NAME} PRIVATE
            /W4
    )
else ()
    target_compile_options(
            ${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()
