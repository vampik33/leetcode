cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME find-largest-value-in-each-tree-row)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_LIST_DIR}/main.cpp")