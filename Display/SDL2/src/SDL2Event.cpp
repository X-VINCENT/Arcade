/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Event
*/

#include "SDL2Event.hpp"

Display::SDLEvent::~SDLEvent()
{
}

Display::KeyType &Display::SDLEvent::getType()
{
    return this->type;
}

void Display::SDLEvent::setType(Display::KeyType type)
{
    this->type = type;
}

extern "C" std::unique_ptr<Display::IEvent> Display::createEvent()
{
    return std::make_unique<Display::SDLEvent>();
}