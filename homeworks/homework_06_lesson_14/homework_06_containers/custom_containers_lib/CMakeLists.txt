cmake_minimum_required(VERSION 3.12)

project(custom_containers_lib)

set(HEADERS
        include/custom_container.hpp
        include/custom_list_container.hpp
        include/custom_sequence_container.hpp
        include/custom_iter.hpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINKER_LANGUAGE CXX
)

find_path(CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS
        NAMES custom_container.hpp
        PATHS ${CMAKE_CURRENT_SOURCE_DIR}
        PATH_SUFFIXES include
)
