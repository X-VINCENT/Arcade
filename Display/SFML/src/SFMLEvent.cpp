/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLEvent
*/

#include "SFMLEvent.hpp"

Display::SFMLEvent::~SFMLEvent()
{
}

Display::KeyType &Display::SFMLEvent::getType()
{
    return this->type;
}

void Display::SFMLEvent::setType(Display::KeyType type)
{
    this->type = type;
}

extern "C" std::unique_ptr<Display::IEvent> Display::createEvent()
{
    return std::make_unique<Display::SFMLEvent>();
}
