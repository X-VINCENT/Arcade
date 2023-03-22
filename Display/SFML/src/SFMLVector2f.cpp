/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#include "SFMLVector2f.hpp"

Display::SFMLVector2f::~SFMLVector2f()
{
}

void Display::SFMLVector2f::create(float x, float y)
{
    this->vector = sf::Vector2f(x, y);
}

float Display::SFMLVector2f::getX()
{
    return this->vector.x;
}

void Display::SFMLVector2f::setX(float x)
{
    this->vector.x = x;
}

float Display::SFMLVector2f::getY()
{
    return this->vector.y;
}

void Display::SFMLVector2f::setY(float y)
{
    this->vector.y = y;
}

sf::Vector2f Display::SFMLVector2f::getSFMLVector2f() const
{
    return this->vector;
}

extern "C" std::unique_ptr<Display::IVector2f> Display::createVector2f()
{
    return std::make_unique<Display::SFMLVector2f>();
}
