/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLSprite
*/

#include "SDL2Sprite.hpp"

Display::SDL2Sprite::SDL2Sprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(src_texture);

    this->texture = sdlTexture.getSDLTexture();
    this->sprite = sdlTexture.getSDLTexture();
    this->position = toSdlVector2f(src_position);
    this->rect = toSdlIntRect(src_rect);
}

Display::SDL2Sprite::~SDL2Sprite()
{
}

Display::IntRect Display::SDL2Sprite::getRect()
{
    return toIIntRect(this->rect);
}

SDL_Rect &Display::SDL2Sprite::getSDLRect()
{
    return this->rect;
}

void Display::SDL2Sprite::setRect(const Display::IntRect &src)
{
    this->rect = toSdlIntRect(src);
}

Display::Vector2f Display::SDL2Sprite::getPosition()
{
    return toIVector2f(this->position);
}

void Display::SDL2Sprite::setPosition(const Display::Vector2f &position)
{
    this->position = toSdlVector2f(position);
}

void Display::SDL2Sprite::setTexture(Display::ITexture &texture)
{
    Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(texture);

    this->texture = sdlTexture.getSDLTexture();
}

void Display::SDL2Sprite::move(const Vector2f &offset)
{
    return;
}

SDL_Texture &Display::SDL2Sprite::getSDLSprite()
{
    return *this->texture;
}
