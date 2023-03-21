/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include "IGameModule.hpp"
#include <iostream>

Game::Snake::Snake() : name("Snake")
{
}

Game::Snake::~Snake()
{
}

void Game::Snake::init()
{
    std::cout << "Snake init" << std::endl;
}

void Game::Snake::stop()
{
    std::cout << "Snake stop" << std::endl;
}

const std::string &Game::Snake::getName() const
{
    return this->name;
}

extern "C" std::unique_ptr<Game::IGameModule> createGame() {
    return std::make_unique<Game::Snake>();
}
