/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameObject.cpp
*/

#include "AGameObject.hpp"

AGameObject::AGameObject(std::pair<int, int> pos, int orientation, char c, Printable::Colors color, std::string path)
    : pos(pos), orientation(orientation), printable(c, color, path)
{
}

const std::pair<int, int> &AGameObject::getPos() const
{
    return pos;
}

void AGameObject::setPos(const std::pair<int, int> &newPos)
{
    this->pos = newPos;
}

int AGameObject::getOrientation() const
{
    return orientation;
}

void AGameObject::setOrientation(int newOrientation)
{
    this->orientation = newOrientation;
}

const Printable &AGameObject::getPrintable() const
{
    return printable;
}

void AGameObject::setPrintable(const char &newC, Printable::Colors newColor, const std::string &newPath)
{
    this->printable.setC(newC);
    this->printable.setColor(newColor);
    this->printable.setPath(newPath);
}
