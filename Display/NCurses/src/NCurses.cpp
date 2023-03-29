/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCurses.cpp
*/

#include "NCurses.hpp"
#include <memory>
#include <iostream>

Display::NCurses::NCurses()
{
    _name = "NCurses";
}

Display::NCurses::~NCurses()
{
}

void Display::NCurses::update()
{
}

void Display::NCurses::destroy()
{
}

extern "C" std::unique_ptr<Display::IDisplayModule> createModule()
{
    return std::make_unique<Display::NCurses>();
}
