/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#include "SDL2Texture.hpp"
#include "SDL2Renderer.hpp"
#include <SDL2/SDL_image.h>

Display::SDL2Texture::SDL2Texture(char c, std::string const &fpath, Display::IRenderer &renderer)
{
    SDL_Renderer *sdlRenderer = dynamic_cast<Display::SDL2Renderer &>(renderer).getSDL2Renderer();

    if (sdlRenderer == nullptr) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

    SDL_Texture *texture = IMG_LoadTexture(sdlRenderer, fpath.c_str());
    if (texture == nullptr) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
    this->texture = texture;
}

Display::SDL2Texture::~SDL2Texture()
{
}

SDL_Texture *Display::SDL2Texture::getSDLTexture() const
{
    return this->texture;
}

extern "C" std::unique_ptr<Display::ITexture> Display::createTexture()
{
    return std::make_unique<Display::SDL2Texture>();
}
