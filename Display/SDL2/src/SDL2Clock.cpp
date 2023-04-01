/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Clock
*/

#include "SDL2Clock.hpp"

Display::SDL2Clock::SDL2Clock()
{
    this->clock = SDL_GetTicks();
}

Display::SDL2Clock::~SDL2Clock()
{
}

int Display::SDL2Clock::getElapsedTime()
{
    return SDL_GetTicks() - this->clock;
}

void Display::SDL2Clock::restart()
{
    this->clock = SDL_GetTicks();
}
