cmake_minimum_required(VERSION 3.10)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

# Add all source files
file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        "src/**/*.cpp"
        "header/*.h"
        "header/**/*.h"
)

add_executable(untitled2 ${SOURCE_FILES})

# Explicitly add all header files
target_include_directories(untitled2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header)
