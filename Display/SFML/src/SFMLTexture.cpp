/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

Display::SFMLTexture::~SFMLTexture()
{
}

void Display::SFMLTexture::load(char c, std::string const &fpath)
{
    this->texture.loadFromFile(fpath);
}

sf::Texture Display::SFMLTexture::getSFMLTexture() const
{
    return this->texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SFMLTexture>();
}
