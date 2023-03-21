/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLIntRect
*/

#include "SFMLIntRect.hpp"

Display::SFMLIntRect::~SFMLIntRect()
{
}

void Display::SFMLIntRect::create(int left, int top, int width, int height)
{
    this->rect = sf::IntRect(left, top, width, height);
}

int Display::SFMLIntRect::getLeft()
{
    return this->rect.left;
}

void Display::SFMLIntRect::setLeft(int left)
{
    this->rect.left = left;
}

int Display::SFMLIntRect::getTop()
{
    return this->rect.top;
}

void Display::SFMLIntRect::setTop(int top)
{
    this->rect.top = top;
}

int Display::SFMLIntRect::getWidth()
{
    return this->rect.width;
}

void Display::SFMLIntRect::setWidth(int width)
{
    this->rect.width = width;
}

int Display::SFMLIntRect::getHeight()
{
    return this->rect.height;
}

void Display::SFMLIntRect::setHeight(int height)
{
    this->rect.height = height;
}

sf::IntRect Display::SFMLIntRect::getSFMLIntRect() const
{
    return this->rect;
}
