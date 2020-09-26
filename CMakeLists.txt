cmake_minimum_required(VERSION 3.13)
project(brainfuck_interpreter)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(brainfuck_interpreter main.cpp TableauMemoire.h Ruban.cpp Ruban.h Program.cpp Program.h)