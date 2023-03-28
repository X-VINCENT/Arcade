/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLSprite
*/

#include "SDL2Sprite.hpp"

Display::SDLSprite::~SDLSprite()
{
}

void Display::SDLSprite::create(
        std::unique_ptr<Display::ITexture> src_texture,
        const Display::IIntRect &src_rect,
        const Display::IVector2f &src_position
)
{   Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(*src_texture);

    this->texture = sdlTexture.getSDLTexture();
    this->sprite = sdlTexture.getSDLTexture();
    this->position = toSdlVector2f(src_position);
    *this->rect = toSdlIntRect(src_rect);
}

