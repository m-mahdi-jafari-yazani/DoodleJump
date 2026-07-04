cmake_minimum_required(VERSION 3.16)

project(DoodleJump)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/sfml@2")

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window system)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(DoodleJump ${SOURCES})

target_include_directories(DoodleJump PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(DoodleJump
    sfml-graphics
    sfml-window
    sfml-system
)