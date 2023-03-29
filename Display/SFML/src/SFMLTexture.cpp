/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "SFMLTexture.hpp"

Display::SFMLTexture::SFMLTexture(
    char c,
    std::string const &fpath,
    Display::IRenderer &renderer
)
{
    (void)c;
    (void)renderer;
    this->texture.loadFromFile(fpath);
}

Display::SFMLTexture::~SFMLTexture()
{
}

sf::Texture &Display::SFMLTexture::getSFMLTexture()
{
    return this->texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SFMLTexture>();
}
