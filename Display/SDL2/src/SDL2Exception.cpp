/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Exception
*/

#include "SDL2Exception.hpp"

Display::SDL2Exception::SDL2Exception(const std::string &message)
    : message("SDL2: " + message)
{
}

Display::SDL2Exception::~SDL2Exception()
{
}

const char *Display::SDL2Exception::what() const noexcept
{
    return message.c_str();
}
