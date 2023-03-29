/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesSprite
*/

#include "NCursesSprite.hpp"
#include "NCursesTexture.hpp"

Display::NCursesSprite::~NCursesSprite()
{
}

Display::NCursesSprite::NCursesSprite(
    std::unique_ptr<ITexture> src_texture,
    const IntRect &src_rect,
    const Vector2f &src_position
)
{
    Display::NCursesTexture ncursesTexture =
            dynamic_cast<Display::NCursesTexture &>(*src_texture);

    // !!Character not set
    this->c = ncursesTexture.getNCursesTexture();
    this->texture = std::move(texture);
    this->rect = src_rect;
    this->position = src_position;
}

Display::IntRect Display::NCursesSprite::getRect()
{
    return this->rect;
}

void Display::NCursesSprite::setRect(const Display::IntRect &src_rect)
{
    this->rect = src_rect;
}

Display::Vector2f Display::NCursesSprite::getPosition()
{
    return this->position;
}

void Display::NCursesSprite::setPosition(const Display::Vector2f &position)
{
    this->position = position;
}

const Display::ITexture &Display::NCursesSprite::getTexture()
{
    return this->texture;
}

void Display::NCursesSprite::setTexture(Display::ITexture &src_texture)
{
    Display::NCursesTexture ncursesTexture =
            dynamic_cast<Display::NCursesTexture &>(src_texture);

    this->c = ncursesTexture.getNCursesTexture();
    this->texture = std::move(src_texture);
}

void Display::NCursesSprite::move(const Vector2f &offset)
{
    this->position.x = this->position.x + offset.x;
    this->position.y = this->position.y + offset.y;
}

extern "C" std::unique_ptr<Display::ISprite> Display::createSprite()
{
    return std::make_unique<Display::NCursesSprite>();
}
