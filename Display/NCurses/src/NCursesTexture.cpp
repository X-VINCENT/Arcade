/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesTexture
*/

#include "NCursesTexture.hpp"

Display::NCursesTexture::NCursesTexture(char c, std::string const &fpath)
{
    (void)fpath;
    this->c = c;
}

Display::NCursesTexture::~NCursesTexture()
{
}

char Display::NCursesTexture::getTexture() const
{
    return this->c;
}
