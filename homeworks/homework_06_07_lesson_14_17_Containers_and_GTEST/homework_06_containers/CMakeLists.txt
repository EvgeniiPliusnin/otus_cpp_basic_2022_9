cmake_minimum_required(VERSION 3.12)

project(custom_containers)

add_subdirectory(custom_containers_lib)
add_subdirectory(src)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

