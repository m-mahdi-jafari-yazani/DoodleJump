cmake_minimum_required(VERSION 3.16)

project(JumpDoodle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/opt/homebrew/opt/sfml@2/lib/cmake/SFML")

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(JumpDoodle ${SOURCES})

target_link_libraries(JumpDoodle
    sfml-graphics
    sfml-window
    sfml-system
)