cmake_minimum_required(VERSION 3.10)
project(ejercicios-practica-2-corte-2)

# Nombre del proyecto
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(twitter      twitter/design_twitter.cpp)
add_executable(spreadsheet  spreadsheet/design_spreadsheet.cpp)
add_executable(robot        robot/robot-simulator.cpp)
add_executable(queen        queen/queen-attack.cpp)
