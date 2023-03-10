cmake_minimum_required(VERSION 3.0)
project(arcade)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
set(EXECUTABLE_NAME "arcade")
set(SRC_DIRECTORY src/)
set(TESTS_DIRECTORY tests/)
set(SRC_MAIN
        main.cpp
)
set(SRC_FILES
        Arcade.cpp
)
set(SRC_TESTS
)
list(TRANSFORM SRC_MAIN PREPEND ${SRC_DIRECTORY})
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIRECTORY})
list(TRANSFORM SRC_TESTS PREPEND ${TESTS_DIRECTORY})
set(CMAKE_CPP_FLAGS "-Wall -Wextra -Werror")
add_executable(${EXECUTABLE_NAME} ${SRC_MAIN} ${SRC_FILES})