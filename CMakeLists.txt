cmake_minimum_required(VERSION 3.0)
project(arcade)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Find the NCurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Find the SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find the SFML library
find_package(SFML 2.5
        COMPONENTS
        system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

include_directories(
        Core/DLLoader/include
        Core/include
        Core/Menu/include
        Display/include
        Display/NCurses/include
        Display/SDL2/include
        Display/SFML/include
        Game/Centipede/include
        Game/include
        Game/Snake/include
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
        Menu/src/Menu.cpp
        src/Arcade.cpp
        src/Handler.cpp
)

# NCurses Sources
set(NCURSES_DIRECTORY NCurses/)
set(SRC_DISPLAY_NCURSES
        src/NCursesClock.cpp
        src/NCursesException.cpp
        src/NCursesFactory.cpp
        src/NCursesFont.cpp
        src/NCursesSprite.cpp
        src/NCursesText.cpp
        src/NCursesTexture.cpp
        src/NCursesWindow.cpp
)

# SDL2 Sources
set(SDL2_DIRECTORY SDL2/)
set(SRC_DISPLAY_SDL2
        src/SDL2Clock.cpp
        src/SDL2Exception.cpp
        src/SDL2Factory.cpp
        src/SDL2Font.cpp
        src/SDL2Sprite.cpp
        src/SDL2Text.cpp
        src/SDL2Texture.cpp
        src/SDL2Window.cpp
)

# SFML Sources
set(SFML_DIRECTORY SFML/)
set(SRC_DISPLAY_SFML
        src/SFMLClock.cpp
        src/SFMLException.cpp
        src/SFMLFactory.cpp
        src/SFMLFont.cpp
        src/SFMLSprite.cpp
        src/SFMLText.cpp
        src/SFMLTexture.cpp
        src/SFMLWindow.cpp
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


set(CMAKE_CPP_FLAGS "-Wall -Wextra -Werror -fno-gnu-unique")

# Transform all paths to absolute paths
list(TRANSFORM SRC_MAIN PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_CORE PREPEND ${CORE_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_NCURSES PREPEND ${DISPLAY_DIRECTORY}/${NCURSES_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_SDL2 PREPEND ${DISPLAY_DIRECTORY}/${SDL2_DIRECTORY})
list(TRANSFORM SRC_DISPLAY_SFML PREPEND ${DISPLAY_DIRECTORY}/${SFML_DIRECTORY})
list(TRANSFORM SRC_GAME_MENU PREPEND ${GAME_DIRECTORY}/${MENU_DIRECTORY})
list(TRANSFORM SRC_GAME_SNAKE PREPEND ${GAME_DIRECTORY}/${SNAKE_DIRECTORY})
list(TRANSFORM SRC_GAME_CENTIPEDE PREPEND ${GAME_DIRECTORY}/${CENTIPEDE_DIRECTORY})

# Display libraries
set(NCURSES_LIB arcade_ncurses)
set(SDL2_LIB arcade_sdl2)
set(SFML_LIB arcade_sfml)

add_library(${NCURSES_LIB} SHARED ${SRC_DISPLAY_NCURSES})
add_library(${SDL2_LIB} SHARED ${SRC_DISPLAY_SDL2})
add_library(${SFML_LIB} SHARED ${SRC_DISPLAY_SFML})

set_target_properties(${NCURSES_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(${SDL2_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(${SFML_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)


# Games libraries
set (SNAKE_LIB arcade_snake)
set (CENTIPEDE_LIB arcade_centipede)

add_library(${SNAKE_LIB} SHARED ${SRC_GAME_SNAKE})
add_library(${CENTIPEDE_LIB} SHARED ${SRC_GAME_CENTIPEDE})

set_target_properties(${SNAKE_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)
set_target_properties(${CENTIPEDE_LIB} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib/)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY})

add_executable(${EXECUTABLE_NAME} ${SRC_MAIN} ${SRC_CORE})

target_link_libraries(${NCURSES_LIB} ${CURSES_LIBRARIES})
target_link_libraries(${SDL2_LIB} ${SDL2_LIBRARIES} SDL2_image SDL2_ttf)
target_link_libraries(${SFML_LIB} sfml-graphics)
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_DL_LIBS})
