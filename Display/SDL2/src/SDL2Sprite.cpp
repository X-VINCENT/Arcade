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
    this->position = src_position;
    this->rect = src_rect;
}

Display::SDL2Sprite::~SDL2Sprite()
{
}

Display::IntRect Display::SDL2Sprite::getRect()
{
    return this->rect;
}

void Display::SDL2Sprite::setRect(const Display::IntRect &src)
{
    this->rect = src;
}

Display::Vector2f Display::SDL2Sprite::getPosition()
{
    return this->position;
}

void Display::SDL2Sprite::setPosition(const Display::Vector2f &position)
{
    this->position = position;
}

void Display::SDL2Sprite::setTexture(Display::ITexture &texture)
{
    Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(texture);

    this->texture = sdlTexture.getSDLTexture();
}

void Display::SDL2Sprite::move(const Vector2f &offset)
{
    this->position.x += offset.x;
    this->position.y += offset.y;
}

SDL_Texture &Display::SDL2Sprite::getTexture()
{
    return *this->texture;
}
