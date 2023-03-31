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
    this->font = TTF_OpenFont(fontPath.c_str(), DEFAULT_SDL2_FONT_SIZE);
    if (!this->font) {
        SDL_Log("Can't load font: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }
}

Display::SDL2Font::~SDL2Font()
{
}

void Display::SDL2Font::setFont(const std::string &fontPath)
{
    this->font = TTF_OpenFont(fontPath.c_str(), DEFAULT_SDL2_FONT_SIZE);
    if (!this->font) {
        SDL_Log("Can't load font: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }
}

TTF_Font *Display::SDL2Font::getSDLFont() const
{
    return this->font;
}
