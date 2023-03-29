/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Texture
*/

#pragma once
#include "ITexture.hpp"
#include "IRenderer.hpp"
#include <SDL2/SDL.h>

namespace Display {
    class SDL2Texture : public ITexture {
        public:
            SDL2Texture(char c, std::string const &fpath, Display::IRenderer &renderer);
            ~SDL2Texture();
            SDL_Texture *getSDLTexture() const;

        private:
            SDL_Texture *texture;
    };
}
