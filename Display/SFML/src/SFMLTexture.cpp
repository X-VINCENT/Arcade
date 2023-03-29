/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

Display::SFMLTexture::SFMLTexture(
    char c,
    std::string const &fpath
)
{
    (void)c;
    this->texture.loadFromFile(fpath);
}

Display::SFMLTexture::~SFMLTexture()
{
}

sf::Texture &Display::SFMLTexture::getSFMLTexture()
{
    return this->texture;
}
