/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLClock
*/

#include "SFMLClock.hpp"

Display::SFMLClock::SFMLClock()
{
    this->clock = sf::Clock();
}

Display::SFMLClock::~SFMLClock()
{
}

int Display::SFMLClock::getElapsedTime()
{
    return this->clock.getElapsedTime().asMilliseconds();
}

void Display::SFMLClock::restart()
{
    this->clock.restart();
}
