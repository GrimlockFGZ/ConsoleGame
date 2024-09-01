cmake_minimum_required(VERSION 3.28)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(untitled2)

target_sources(untitled2 PRIVATE
        src/terminal.cpp
        src/InputSelection.cpp
        src/managers/OptionsManager.cpp
        src/managers/CombatManager.cpp
        src/managers/LootingManager.cpp
        src/Player.cpp
)

target_include_directories(untitled2 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

target_link_libraries(untitled2 PRIVATE
)
