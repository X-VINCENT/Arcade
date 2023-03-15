cmake_minimum_required(VERSION 3.0)
project(arcade)
set(CMAKE_CXX_STANDARD 20)

include_directories(
        Core/DLLoader/include
        Core/include
        Display/NCurses/include
        Display/include
        Game/Snake/include
        Game/include
)

set(EXECUTABLE_NAME "arcade")
set(CORE_DIRECTORY Core/)
set(DISPLAY_DIRECTORY Display/)
set(GAME_DIRECTORY Game/)
set(TESTS_DIRECTORY tests/)

set(SRC_MAIN
        src/main.cpp
)

set(SRC_CORE
        DLLoader/src/DLLoader.cpp
        src/Arcade.cpp)

set(SRC_DISPLAY
        NCurses/src/NCurses.cpp
        Window/include/IWindow.hpp
        Texture/include/ITexture.hpp
        Sprite/include/ISprite.hpp
        Window/NCurses/include/NCursesWindow.hpp
        Window/NCurses/src/NCursesWindow.cpp)

set(SRC_GAME
        Snake/src/Snake.cpp
        src/AGameObject.cpp
        src/Printable.cpp
)

set(SRC_TESTS
)

set(CMAKE_CPP_FLAGS "-Wall -Wextra -Werror")

list(TRANSFORM SRC_MAIN PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_CORE PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_DISPLAY PREPEND ${DISPLAY_DIRECTORY})
list(TRANSFORM SRC_GAME PREPEND ${GAME_DIRECTORY})
list(TRANSFORM SRC_TESTS PREPEND ${TESTS_DIRECTORY})

add_library(games SHARED ${SRC_GAME})
add_library(displays SHARED ${SRC_DISPLAY})

add_executable(${EXECUTABLE_NAME} ${SRC_MAIN} ${SRC_CORE})
