cmake_minimum_required(VERSION 3.21)
project(stack_static C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-Wall -Wpedantic")

add_executable(${PROJECT_NAME} src/myStack.c)