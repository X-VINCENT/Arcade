/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Font
*/

#include "SDL2Font.hpp"
#include "SDL2Exception.hpp"
#include <iostream>

#define DEFAULT_SDL2_FONT_SIZE 24

Display::SDL2Font::SDL2Font(std::string const &fontPath)
{
    try {
        this->font = TTF_OpenFont(fontPath.c_str(), DEFAULT_SDL2_FONT_SIZE);
        if (!this->font)
            throw SDL2Exception("Can't load font " + fontPath);
    } catch (SDL2Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Display::SDL2Font::~SDL2Font()
{
}

void Display::SDL2Font::setFont(const std::string &fontPath)
{
    try {
        this->font = TTF_OpenFont(fontPath.c_str(), DEFAULT_SDL2_FONT_SIZE);
        if (!this->font)
            throw SDL2Exception("Can't load font " + fontPath);
    } catch (SDL2Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

TTF_Font *Display::SDL2Font::getSDLFont() const
{
    return this->font;
}
