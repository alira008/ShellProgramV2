cmake_minimum_required(VERSION 3.0)

project(Shell)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "-Wall -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e4717df71a4f45bf9f0ac88c6cd9846a0bc248dd.zip
)

FetchContent_MakeAvailable(googletest)

ADD_EXECUTABLE(Tests
    tests/parser_tests.cpp
    src/parser/vector_parser.cpp
    src/parser/comment_parser.cpp 
    src/parser/group_parser.cpp
    src/parser/connector_parser.cpp
)

ADD_EXECUTABLE(MyShell
    src/main.cpp 
    src/shell/shell.cpp 
    src/parser/vector_parser.cpp
    src/parser/comment_parser.cpp 
    src/parser/group_parser.cpp
    src/parser/connector_parser.cpp
)

target_link_libraries(Tests gtest_main)