/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Printable.cpp
*/

#include <utility>

#include "Printable.hpp"

Printable::Printable(char c, Colors color, std::string path) : c(c), color(color), path(std::move(path))
{
}

const char &Printable::getC() const
{
    return c;
}

void Printable::setC(const char &newC)
{
    this->c = newC;
}

Printable::Colors Printable::getColor() const
{
    return color;
}

void Printable::setColor(Colors newColor)
{
    this->color = newColor;
}

const std::string &Printable::getPath() const
{
    return path;
}

void Printable::setPath(const std::string &newPath)
{
    this->path = newPath;
}
