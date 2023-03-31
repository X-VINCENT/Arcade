/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#include "SDL2Texture.hpp"
#include <SDL2/SDL_image.h>
#include <string>

Display::SDL2Texture::SDL2Texture(
    char c,
    std::string const &texturePath,
    SDL_Renderer *renderer
)
{
    if (!renderer) {
        SDL_Log("Invalid renderer: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

    this->texture = IMG_LoadTexture(renderer, texturePath.c_str());
    if (!this->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
}

Display::SDL2Texture::~SDL2Texture()
{
}

SDL_Texture *Display::SDL2Texture::getSDLTexture() const
{
    return this->texture;
}
