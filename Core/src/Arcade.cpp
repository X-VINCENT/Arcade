/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "Handler.hpp"

int arcade(std::string const &displayLibPath)
{
    Core::Handler handler(displayLibPath);

    handler.loop();

    return SUCCESS;
}
