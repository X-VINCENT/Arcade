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

void Display::NCurses::create()
{
    std::cout << "ncurse";
}

void Display::NCurses::update()
{
}

void Display::NCurses::destroy()
{
}

Display::NCurses::~NCurses() = default;

extern "C" std::unique_ptr<Display::IDisplayModule> createModule()
{
    return std::make_unique<Display::NCurses>();
}
