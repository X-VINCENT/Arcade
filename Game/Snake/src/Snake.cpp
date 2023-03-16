/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include "IGameModule.hpp"
#include <memory>

Game::Snake::Snake() : name("Snake")
{
}
Game::Snake::~Snake() = default;
void Game::Snake::init()
{
    std::cout << "Snake init" << std::endl;
}
void Game::Snake::stop()
{
    std::cout << "Snake stop" << std::endl;
}
extern "C" const std::string &Game::Snake::getName() const
{
    return this->name;
}
const std::vector<Game::IGameObject> &Game::Snake::getObjects() const
{
}

extern "C" std::unique_ptr<Game::IGameModule> createGame() {
    return std::make_unique<Game::Snake>();
}
