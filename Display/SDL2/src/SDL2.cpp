/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"
#include <memory>
#include <iostream>

Display::SDL2::SDL2()
{
    _name = "SDL2";
}

void Display::SDL2::update()
{
}

void Display::SDL2::destroy()
{
}

Display::SDL2::~SDL2() = default;

extern "C" std::unique_ptr<Display::IDisplayModule> createModule()
{
    return std::make_unique<Display::SDL2>();
}