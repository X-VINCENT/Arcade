/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLException
*/

#include "SFMLException.hpp"

Display::SFMLException::SFMLException(const std::string &message)
    : message("SFML: " + message)
{
}

Display::SFMLException::~SFMLException()
{
}

const char *Display::SFMLException::what() const noexcept
{
    return message.c_str();
}
