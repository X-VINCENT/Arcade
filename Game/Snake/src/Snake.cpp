/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

Snake::Snake()
{
    _name = "Snake";
}

Snake::~Snake()
{
}

extern "C" void Snake::init()
{
    std::cout << "Snake init" << std::endl;
}

extern "C" void Snake::stop()
{
    std::cout << "Snake stop" << std::endl;
}

extern "C" const std::string &Snake::getName() const
{
    return _name;
}
