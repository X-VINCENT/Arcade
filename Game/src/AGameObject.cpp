/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameObject.cpp
*/

#include "AGameObject.hpp"

#include <utility>

Game::AGameObject::AGameObject(std::pair<int, int> pos, int orientation,
        char c, IColor color, std::string path)
    : pos(std::move(pos)), orientation(orientation)
{
}

const std::pair<int, int> &Game::AGameObject::getPos() const
{
    return pos;
}

void Game::AGameObject::setPos(const std::pair<int, int> &newPos)
{
    this->pos = newPos;
}

int Game::AGameObject::getOrientation() const
{
    return orientation;
}

void Game::AGameObject::setOrientation(int newOrientation)
{
    this->orientation = newOrientation;
}

const Game::Printable &Game::AGameObject::getPrintable() const
{
}

void Game::AGameObject::setPrintable(const char &newC, IColor newColor,
        const std::string &newPath)
{
}
