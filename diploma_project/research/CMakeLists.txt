cmake_minimum_required(VERSION 3.12)

project(research)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(video_capture video_capture.cpp )
target_link_libraries( video_capture ${OpenCV_LIBS} )

set_target_properties(video_capture PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )

if (MSVC)
    target_compile_options(video_capture PRIVATE
        /W4
        )
else ()
    target_compile_options(video_capture PRIVATE
        -Wall -Wextra -pedantic -Werror
        )
endif()


