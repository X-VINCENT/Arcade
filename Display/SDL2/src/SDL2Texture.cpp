/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#include "SDL2Texture.hpp"
#include "SDL2Renderer.hpp"
#include <iostream>

Display::SDL2Texture::~SDL2Texture()
{
}

void Display::SDL2Texture::load(char c, std::string const &fpath, std::unique_ptr<Display::IRenderer> renderer)
{
    Display::SDL2Renderer sdl2Renderer = dynamic_cast<Display::SDL2Renderer &>(*renderer);
    SDL_Renderer *sdlRenderer = sdl2Renderer.getSDL2Renderer();

    this->_texture = SDL_CreateTextureFromSurface(sdlRenderer, SDL_LoadBMP(fpath.c_str()));
}

std::unique_ptr<Display::ITexture> Display::SDL2Texture::clone() const
{
    return std::make_unique<Display::SDL2Texture>(*this);
}

SDL_Texture *Display::SDL2Texture::getSDLTexture() const
{
    return this->_texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SDL2Texture>();
}