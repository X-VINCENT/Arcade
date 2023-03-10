/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"

int arcade()
{
    std::string libName = "arcade_snake.so";
    DLLoader<IGameModule> snake(libName);

    snake.getInstance("init")();
    snake.getInstance("stop")();
    return SUCCESS;
}
