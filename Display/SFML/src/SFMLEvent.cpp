/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEvent
*/

#include "SFMLEvent.hpp"

Display::KeyType Display::SFMLEvent::getType()
{
    return this->type;
}

void Display::SFMLEvent::setType(Display::KeyType type)
{
    this->type = type;
}
