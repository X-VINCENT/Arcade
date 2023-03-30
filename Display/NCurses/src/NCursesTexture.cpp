/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesTexture
*/

#include "NCursesTexture.hpp"

Display::NCursesTexture::NCursesTexture(char c)
{
    this->c = c;
}

Display::NCursesTexture::~NCursesTexture()
{
}

char Display::NCursesTexture::getChar() const
{
    return this->c;
}
