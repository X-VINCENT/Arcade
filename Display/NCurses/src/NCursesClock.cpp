/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesClock
*/

#include "NCursesClock.hpp"
#include <ncurses.h>
#include <ctime>

Display::NCursesClock::NCursesClock()
{
    this->startClock = clock();
}

Display::NCursesClock::~NCursesClock()
{
}

int Display::NCursesClock::getElapsedTime()
{
    return static_cast<int>(clock() - this->startClock) / 1000;
}

void Display::NCursesClock::restart()
{
    this->startClock = clock();
}
