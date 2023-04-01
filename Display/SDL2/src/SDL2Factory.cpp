/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Factory
*/

#include "SDL2Factory.hpp"
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
    try {
        if (this->window != nullptr)
            throw SDL2Exception("Window already created");
    } catch (SDL2Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }

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
    std::string const &texturePath
)
{
    return std::make_unique<Display::SDL2Texture>(c, texturePath, this->window->getRenderer());
}

std::unique_ptr<Display::IFont> Display::SDL2Factory::createFont(
    std::string const &fontPath
)
{
    return std::make_unique<Display::SDL2Font>(fontPath);
}

std::unique_ptr<Display::IText> Display::SDL2Factory::createText(
    const std::string &text,
    const Display::IFont &font,
    const Display::Color &color,
    const Display::Vector2f &position
)
{
    return std::make_unique<Display::SDL2Text>(text, font, color, position, this->window->getRenderer());
}

std::unique_ptr<Display::IClock> Display::SDL2Factory::createClock()
{
    return std::make_unique<Display::SDL2Clock>();
}

extern "C" std::unique_ptr<Display::IFactory> createFactory()
{
    return std::make_unique<Display::SDL2Factory>();
}
