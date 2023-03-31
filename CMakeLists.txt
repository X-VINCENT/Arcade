cmake_minimum_required(VERSION 3.0)
project(arcade)
set(CMAKE_CXX_STANDARD 20)

# Find the NCurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Find the SFML library
find_package(SFML 2.5
        COMPONENTS
        system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# Find the SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(
        Core/include
        Core/DLLoader/include
        Display/include
        Display/SFML/include
        Display/NCurses/include
        Display/SDL2/include
        Game/include
        Game/Snake/include
        Game/Centipede/include
)

set(EXECUTABLE_NAME "arcade")
set(DISPLAY_DIRECTORY Display/)
set(GAME_DIRECTORY Game/)

set(SRC_MAIN
        src/main.cpp
)

# Core Sources
set(CORE_DIRECTORY Core/)
set(SRC_CORE
        DLLoader/src/DLLoader.cpp
        src/Arcade.cpp
)

# NCurses Sources
set(NCURSES_DIRECTORY NCurses/)
set(SRC_DISPLAY_NCURSES
        src/NCursesFactory.cpp
        src/NCursesSprite.cpp
        src/NCursesTexture.cpp
        src/NCursesWindow.cpp
)

# SFML Sources
set(SFML_DIRECTORY SFML/)
set(SRC_DISPLAY_SFML
        src/SFMLFactory.cpp
        src/SFMLSprite.cpp
        src/SFMLTexture.cpp
        src/SFMLWindow.cpp
)

# SDL2 Sources
set(SDL2_DIRECTORY SDL2/)
set(SRC_DISPLAY_SDL2
        src/SDL2Factory.cpp
        src/SDL2Sprite.cpp
        src/SDL2Texture.cpp
        src/SDL2Window.cpp
)

# Snake Sources
set(SNAKE_DIRECTORY Snake/)
set(SRC_GAME_SNAKE
        src/Snake.cpp
)

# Centipede Sources
set(CENTIPEDE_DIRECTORY Centipede/)
set(SRC_GAME_CENTIPEDE
        src/Centipede.cpp
)

# Tests Sources
set(TESTS_DIRECTORY tests/)
set(SRC_TESTS
)

set(CMAKE_CPP_FLAGS "-Wall -Wextra -Werror -fno-gnu-unique")

list(TRANSFORM SRC_MAIN PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_CORE PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_NCURSES PREPEND ${DISPLAY_DIRECTORY}/${NCURSES_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_SFML PREPEND ${DISPLAY_DIRECTORY}/${SFML_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_SDL2 PREPEND ${DISPLAY_DIRECTORY}/${SDL2_DIRECTORY})
list(TRANSFORM SRC_GAME_SNAKE PREPEND ${GAME_DIRECTORY}/${SNAKE_DIRECTORY})
list(TRANSFORM SRC_GAME_CENTIPEDE PREPEND ${GAME_DIRECTORY}/${CENTIPEDE_DIRECTORY})
list(TRANSFORM SRC_TESTS PREPEND ${TESTS_DIRECTORY})

add_library(ncurses SHARED ${SRC_DISPLAY_NCURSES})
add_library(sfml SHARED ${SRC_DISPLAY_SFML})
add_library(sdl2 SHARED ${SRC_DISPLAY_SDL2})
add_library(snake SHARED ${SRC_GAME_SNAKE})
add_library(centipede SHARED ${SRC_GAME_CENTIPEDE})

set_target_properties(ncurses PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(sfml PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(sdl2 PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(snake PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(centipede PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

add_executable(${EXECUTABLE_NAME} ${SRC_MAIN} ${SRC_CORE})

target_link_libraries(ncurses ${CURSES_LIBRARIES})
target_link_libraries(sfml sfml-graphics)
target_link_libraries(sdl2 ${SDL2_LIBRARIES} SDL2_image)
target_link_libraries(arcade ${CMAKE_DL_LIBS})
