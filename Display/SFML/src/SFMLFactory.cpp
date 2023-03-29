/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLFactory
*/

#include "SFMLFactory.hpp"
#include <memory>
#include <iostream>

Display::SFMLFactory::~SFMLFactory()
{
}

std::unique_ptr<Display::IWindow> Display::SFMLFactory::createWindow(
    std::string const &title,
    int framerate,
    int width,
    int height
)
{
    return std::make_unique<Display::SFMLWindow>(title, framerate, width, height);
}

std::unique_ptr<Display::ISprite> Display::SFMLFactory::createSprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    return std::make_unique<Display::SFMLSprite>(src_texture, src_rect, src_position);
}

std::unique_ptr<Display::ITexture> Display::SFMLFactory::createTexture(
    char c,
    std::string const &fpath
    )
{
    return std::make_unique<Display::SFMLTexture>(c, fpath);
}

extern "C" std::unique_ptr<Display::IFactory> createFactory()
{
    return std::make_unique<Display::SFMLFactory>();
}
