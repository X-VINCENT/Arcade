/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesVector2f
*/

#include "NCursesVector2f.hpp"

Display::NCursesVector2f::~NCursesVector2f()
{
}

void Display::NCursesVector2f::create(
    float x,
    float y
)
{
    this->x = x;
    this->y = y;
}

float Display::NCursesVector2f::getX()
{
    return this->x;
}

void Display::NCursesVector2f::setX(float x)
{
    this->x = x;
}

float Display::NCursesVector2f::getY()
{
    return this->y;
}

void Display::NCursesVector2f::setY(float y)
{
    this->y = y;
}

extern "C" std::unique_ptr<Display::IVector2f> Display::createVector2f()
{
    return std::make_unique<Display::NCursesVector2f>();
}
