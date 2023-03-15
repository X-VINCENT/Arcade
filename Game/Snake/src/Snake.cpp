/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

Game::Snake::Snake() : name("Snake")
{
}

Game::Snake::~Snake() = default;

extern "C" void Game::Snake::init()
{
    std::cout << "Snake init" << std::endl;
}

extern "C" void Game::Snake::stop()
{
    std::cout << "Snake stop" << std::endl;
}

extern "C" const std::string &Game::Snake::getName() const
{
    return this->name;
}

extern "C" const std::vector<Game::IGameObject> &Game::Snake::getObjects() const
{
}
