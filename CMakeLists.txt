cmake_minimum_required(VERSION 3.10)

project(astar_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(include)

add_library(GAMELIB STATIC src/game.cpp src/state.cpp src/a_star.cpp)

add_executable(astar_game_exe solution.cpp)
target_link_libraries(astar_game_exe GAMELIB)

