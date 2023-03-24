/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesTexture
*/

#include "NCursesTexture.hpp"

Display::NCursesTexture::~NCursesTexture()
{
}

void Display::NCursesTexture::load(char c, std::string const &fpath)
{
    this->c = c;
}

char Display::NCursesTexture::getNCursesTexture() const
{
    return this->c;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::NCursesTexture>();
}
