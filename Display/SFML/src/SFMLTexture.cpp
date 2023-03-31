/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

Display::SFMLTexture::SFMLTexture(std::string const &texturePath)
{
    this->texture.loadFromFile(texturePath);
}

Display::SFMLTexture::~SFMLTexture()
{
}

sf::Texture &Display::SFMLTexture::getSFTexture()
{
    return this->texture;
}
