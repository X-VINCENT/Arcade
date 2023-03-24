/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesEvent
*/

#include "NCursesEvent.hpp"

Display::NCursesEvent::~NCursesEvent()
{
}

Display::KeyType &Display::NCursesEvent::getType()
{
    return this->type;
}

void Display::NCursesEvent::setType(Display::KeyType type)
{
    this->type = type;
}

extern "C" std::unique_ptr<Display::IEvent> Display::createEvent()
{
    return std::make_unique<Display::NCursesEvent>();
}
