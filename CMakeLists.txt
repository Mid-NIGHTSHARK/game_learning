cmake_minimum_required(VERSION 4.4.0)
project(game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib)

add_executable(game
    src/game.cpp
)

target_link_libraries(
    game PRIVATE raylib
)
