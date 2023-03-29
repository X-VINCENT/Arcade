/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesSprite
*/

#include "NCursesSprite.hpp"
#include "NCursesTexture.hpp"

Display::NCursesSprite::NCursesSprite(
    Display::ITexture &texture,
    const IntRect &rect,
    const Vector2f &position
)
{
    Display::NCursesTexture ncursesTexture = dynamic_cast<Display::NCursesTexture &>(texture);

    // !!Character not set
    this->c = ncursesTexture.getNCursesTexture();
    this->texture = texture;
    this->rect = rect;
    this->position = position;
}

Display::NCursesSprite::~NCursesSprite()
{
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
