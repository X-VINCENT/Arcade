/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLSprite
*/

#include "SDL2Sprite.hpp"

Display::SDL2Sprite::~SDL2Sprite()
{
}

void Display::SDL2Sprite::create(
        std::unique_ptr<Display::ITexture> src_texture,
        const Display::IIntRect &src_rect,
        const Display::IVector2f &src_position
)
{   Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(*src_texture);

    this->texture = sdlTexture.getSDLTexture();
    this->sprite = sdlTexture.getSDLTexture();
    this->position = toSdlVector2f(src_position);
    this->rect = toSdlIntRect(src_rect);
}

Display::IIntRect Display::SDL2Sprite::getRect() {
    return toIIntRect(this->rect);
}

SDL_Rect &Display::SDL2Sprite::getSDLRect() {
    return this->rect;
}

void Display::SDL2Sprite::setRect(const Display::IIntRect &src) {
    this->rect = toSdlIntRect(src);
}

Display::IVector2f Display::SDL2Sprite::getPosition() {
    return toIVector2f(this->position);
}

void Display::SDL2Sprite::setPosition(const Display::IVector2f &position) {
    this->position = toSdlVector2f(position);
}

std::unique_ptr<Display::ITexture> Display::SDL2Sprite::getTexture() {
    std::unique_ptr<Display::SDL2Texture> text =
            std::make_unique<Display::SDL2Texture>();

    return text;
}

void Display::SDL2Sprite::setTexture(std::unique_ptr<Display::ITexture> texture) {
    Display::SDL2Texture sdlTexture = dynamic_cast<Display::SDL2Texture &>(*texture);

    this->texture = sdlTexture.getSDLTexture();
}

void Display::SDL2Sprite::move(const IVector2f &offset) {
    return;
}

SDL_Texture &Display::SDL2Sprite::getSDLSprite() {
    return *this->texture;
}

extern "C" std::unique_ptr<Display::ISprite> Display::createSprite() {
    return std::make_unique<Display::SDL2Sprite>();
}
