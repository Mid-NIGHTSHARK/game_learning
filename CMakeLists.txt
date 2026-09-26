cmake_minmum_required(VERSION 4.4.3)
project(game)

add_executable(game
    src/game.cpp
)
target_link_libraries(
    game PRIVATE raylib
)
