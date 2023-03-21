/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesEvent
*/

#include "NCursesEvent.hpp"

Display::KeyType Display::NCursesEvent::getType()
{
    return this->type;
}

void Display::NCursesEvent::setType(Display::KeyType type)
{
    this->type = type;
}
