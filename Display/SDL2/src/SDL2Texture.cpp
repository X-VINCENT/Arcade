/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#include "SDL2Texture.hpp"

Display::SDL2Texture::~SDL2Texture()
{
}

void Display::SDL2Texture::load(char c, std::string const &fpath)
{
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, SDL_LoadBMP(fpath.c_str()));
}

SDL_Texture *Display::SDL2Texture::getSDLTexture() const
{
    return this->_texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SDL2Texture>();
}