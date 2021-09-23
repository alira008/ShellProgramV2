cmake_minimum_required(VERSION 3.0)

project(Shell)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-Wall -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

ADD_EXECUTABLE(MyShell 
    src/main.cpp 
    src/shell/shell.cpp 
    src/parser/comment_parser.cpp 
    src/parser/group_parser.cpp
    src/parser/connect_parser.cpp
)