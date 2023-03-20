/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFML
*/

#include "SFML.hpp"
#include <memory>
#include <iostream>

Display::SFML::SFML()
{
    _name = "SFML";
}

void Display::SFML::create()
{
    std::cout << "SFML";
}

void Display::SFML::update()
{
}

void Display::SFML::destroy()
{
}

Display::SFML::~SFML() = default;

extern "C" std::unique_ptr<Display::IDisplayModule> createModule()
{
    return std::make_unique<Display::SFML>();
}
