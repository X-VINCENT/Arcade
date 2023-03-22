/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesIntRect
*/

#include "NCursesIntRect.hpp"

Display::NCursesIntRect::~NCursesIntRect()
{
}

void Display::NCursesIntRect::create(
    int left,
    int top,
    int width,
    int height
)
{
    this->left = left;
    this->top = top;
    this->width = width;
    this->height = height;
}

int Display::NCursesIntRect::getLeft()
{
    return this->left;
}

void Display::NCursesIntRect::setLeft(int left)
{
    this->left = left;
}

int Display::NCursesIntRect::getTop()
{
    return this->top;
}

void Display::NCursesIntRect::setTop(int top)
{
    this->top = top;
}

int Display::NCursesIntRect::getWidth()
{
    return this->width;
}

void Display::NCursesIntRect::setWidth(int width)
{
    this->width = width;
}

int Display::NCursesIntRect::getHeight()
{
    return this->height;
}

void Display::NCursesIntRect::setHeight(int height)
{
    this->height = height;
}

extern "C" std::unique_ptr<Display::IIntRect> Display::createIntRect()
{
    return std::make_unique<Display::NCursesIntRect>();
}
