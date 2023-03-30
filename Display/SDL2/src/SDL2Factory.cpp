/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Factory
*/

#include "SDL2Factory.hpp"
#include <memory>
#include <iostream>

Display::SDL2Factory::~SDL2Factory()
{
}

std::unique_ptr<Display::IWindow> Display::SDL2Factory::createWindow(
    const std::string &title,
    int framerate,
    int width,
    int height
)
{
    if (this->window != nullptr)
        throw 1;

    auto winptr = std::make_unique<Display::SDL2Window>(title, framerate, width, height);
    this->window = winptr.get();
    return winptr;
}

std::unique_ptr<Display::ISprite> Display::SDL2Factory::createSprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    return std::make_unique<Display::SDL2Sprite>(src_texture, src_rect, src_position);
}

std::unique_ptr<Display::ITexture> Display::SDL2Factory::createTexture(
    char c,
    std::string const &fpath
)
{
    return std::make_unique<Display::SDL2Texture>(c, fpath, this->window->getRenderer());
}

extern "C" std::unique_ptr<Display::IFactory> createFactory()
{
    return std::make_unique<Display::SDL2Factory>();
}
