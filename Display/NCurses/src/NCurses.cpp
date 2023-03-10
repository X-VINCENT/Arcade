/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCurses.cpp
*/

#include "../include/NCurses.hpp"

NCurses::NCurses()
{
    _name = "NCurses";
}

NCurses::~NCurses()
{
}

void NCurses::init()
{
}

void NCurses::stop()
{
}

const std::string &NCurses::getName() const
{
    return _name;
}
