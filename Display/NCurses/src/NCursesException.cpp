/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesException
*/

#include "NCursesException.hpp"

Display::NCursesException::NCursesException(const std::string &message)
    : message("NCurses: " + message)
{
}

Display::NCursesException::~NCursesException()
{
}

const char *Display::NCursesException::what() const noexcept
{
    return message.c_str();
}
