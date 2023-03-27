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

std::unique_ptr<Display::ITexture> Display::SFMLTexture::clone() const
{
    return std::make_unique<Display::SFMLTexture>(*this);
}

sf::Texture &Display::SFMLTexture::getSFMLTexture()
{
    return this->texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SFMLTexture>();
}
