/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesTexture
*/

#include "NCursesTexture.hpp"

Display::NCursesTexture::NCursesTexture(char c, std::string const &fpath, Display::IRenderer &renderer)
{
    (void)fpath;
    (void)renderer;
    this->c = c;
}

Display::NCursesTexture::~NCursesTexture()
{
}

char Display::NCursesTexture::getNCursesTexture() const
{
    return this->c;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::NCursesTexture>();
}
