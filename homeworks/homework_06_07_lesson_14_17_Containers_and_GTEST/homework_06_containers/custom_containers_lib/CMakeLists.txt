cmake_minimum_required(VERSION 3.12)

#############################################################
#               Library section
#############################################################
project(custom_containers_lib)

set(HEADERS
        include/custom_list_container.hpp
        include/custom_sequence_container.hpp
        include/custom_iterator.hpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINKER_LANGUAGE CXX
)

find_path(CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS
        NAMES custom_iterator.hpp
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}
        PATH_SUFFIXES include
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


#############################################################
#                       TESTS section
#############################################################
set(BUILD_TESTS true)
if (BUILD_TESTS)
    enable_testing()

    find_package(GTest REQUIRED )

    add_executable(containers_tests
            test/tests_main.cpp
            test/double_linked_list_tests.cpp
            test/sequence_container_tests.cpp
            )

    target_include_directories(containers_tests PRIVATE "${CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS}" "${CMAKE_CURRENT_SOURCE_DIR}/test")

    # Add googletest to the include directories for the test target
    include(GoogleTest)
    target_include_directories(containers_tests PRIVATE GTest)
    target_include_directories(containers_tests PRIVATE ${GTEST_BOTH_LIBRARIES})
    target_include_directories(containers_tests PRIVATE ${GTEST_INCLUDE_DIRS})

    # Link test target against gtest libraries
    target_link_libraries(containers_tests PRIVATE ${GTEST_BOTH_LIBRARIES})
#    target_link_libraries(containers_tests PRIVATE gtest gtest_main gmock gmock_main)

    set_target_properties(containers_tests PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            )

    if (MSVC)
        target_compile_options(containers_tests PRIVATE
                /W4
                )
    else ()
        target_compile_options(containers_tests PRIVATE
                -Wall -Wextra -pedantic -Werror
                )
    endif()
endif ()
