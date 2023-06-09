/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCurses.cpp
*/

#include "NCursesFactory.hpp"

Display::NCursesFactory::~NCursesFactory()
{
}

std::unique_ptr<Display::IWindow> Display::NCursesFactory::createWindow(
    const std::string &title,
    int framerate,
    int width,
    int height
)
{
    return std::make_unique<Display::NCursesWindow>(title, framerate, width, height);
}

std::unique_ptr<Display::ISprite> Display::NCursesFactory::createSprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    return std::make_unique<Display::NCursesSprite>(src_texture, src_rect, src_position);
}

std::unique_ptr<Display::ITexture> Display::NCursesFactory::createTexture(
    char c,
    std::string const &texturePath
)
{
    return std::make_unique<Display::NCursesTexture>(c);
}

std::unique_ptr<Display::IFont> Display::NCursesFactory::createFont(
    std::string const &fontPath
)
{
    return std::make_unique<Display::NCursesFont>();
}

std::unique_ptr<Display::IText> Display::NCursesFactory::createText(
    const std::string &text,
    const Display::IFont &font,
    const Display::Color &color,
    const Display::Vector2f &position
)
{
    return std::make_unique<Display::NCursesText>(text, color, position);
}

std::unique_ptr<Display::IClock> Display::NCursesFactory::createClock()
{
    return std::make_unique<Display::NCursesClock>();
}

extern "C" std::unique_ptr<Display::IFactory> createFactory()
{
    return std::make_unique<Display::NCursesFactory>();
}
