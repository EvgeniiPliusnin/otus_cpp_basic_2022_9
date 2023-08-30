cmake_minimum_required(VERSION 3.12)

project(custom_containers_lib)

set(HEADERS
        include/custom_list_container.hpp
        include/custom_sequence_container.hpp
        include/custom_iterator.hpp
)

add_subdirectory(test)

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
