/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

Display::ITexture &Display::SFMLTexture::load(char c, const std::string fpath)
{
    this->texture->loadFromFile(fpath);
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture() {
    return std::make_unique<Display::SFMLTexture>();
}
