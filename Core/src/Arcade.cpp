/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "NCurses.hpp"

int arcade()
{
    std::string libName = "arcade_snake.so";
    DLLoader<IGameModule> snake(libName);
    DLLoader<NCurses> display("arcade_ncurses.so");

    snake.getInstance("init")();
    snake.getInstance("stop")();
    return SUCCESS;
}
