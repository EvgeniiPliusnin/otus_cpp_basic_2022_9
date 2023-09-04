cmake_minimum_required(VERSION 3.12)

project(custom_containers)

add_executable(${PROJECT_NAME}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CUSTOM_CONTAINERS_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE custom_containers_lib)

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/custom_iter)
#target_link_libraries(${PROJECT_NAME} PRIVATE custom_iter_lib)