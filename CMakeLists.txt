cmake_minimum_required(VERSION 3.0)
project(arcade)
set(CMAKE_CXX_STANDARD 20)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(
        Core/DLLoader/include
        Core/include
        Display/NCurses/include
        Display/include
        Game/Snake/include
        Game/include
        Display/SFML/include
)

set(EXECUTABLE_NAME "arcade")
set(CORE_DIRECTORY Core/)
set(DISPLAY_DIRECTORY Display/)
set(GAME_DIRECTORY Game/)
set(NCURSES_DIRECTORY NCurses/)
set(SFML_DIRECTORY SFML/)
set(SNAKE_DIRECTORY Snake/)
set(TESTS_DIRECTORY tests/)

set(SRC_MAIN
        src/main.cpp
)

set(SRC_CORE
        DLLoader/src/DLLoader.cpp
        src/Arcade.cpp
        ../Game/src/AGameObject.cpp
        )

set(SRC_DISPLAY_NCURSES
        src/NCurses.cpp
        src/NCursesWindow.cpp)

set(SRC_DISPLAY_SFML
        src/SFML.cpp
        src/SFMLWindow.cpp)

set(SRC_GAME_SNAKE
        src/Snake.cpp
        )

set (SRC_DISPLAY_SFML
        src/SFML.cpp
        src/SFMLWindow.cpp
        )

set(SRC_TESTS
)

set(CMAKE_CPP_FLAGS "-Wall -Wextra -Werror -fno-gnu-unique")

list(TRANSFORM SRC_MAIN PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_CORE PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_NCURSES PREPEND
        ${DISPLAY_DIRECTORY}/${NCURSES_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_SFML PREPEND ${DISPLAY_DIRECTORY}/${SFML_DIRECTORY})
list(TRANSFORM SRC_GAME_SNAKE PREPEND ${GAME_DIRECTORY}/${SNAKE_DIRECTORY})
list(TRANSFORM SRC_TESTS PREPEND ${TESTS_DIRECTORY})

add_library(ncurses SHARED ${SRC_DISPLAY_NCURSES})
add_library(sfml SHARED ${SRC_DISPLAY_SFML})
add_library(snake SHARED ${SRC_GAME_SNAKE})

set_target_properties(sfml PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(ncurses PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(snake PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

add_executable(${EXECUTABLE_NAME} ${SRC_MAIN} ${SRC_CORE})

target_link_libraries(ncurses ${CURSES_LIBRARIES})
