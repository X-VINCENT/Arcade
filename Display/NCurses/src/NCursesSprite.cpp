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

    this->c = ncursesTexture.getChar();
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

void Display::NCursesSprite::setRect(const Display::IntRect &src)
{
    this->rect = src;
}

Display::Vector2f Display::NCursesSprite::getPosition()
{
    return this->position;
}

void Display::NCursesSprite::setPosition(const Display::Vector2f &src)
{
    this->position = src;
}

void Display::NCursesSprite::setTexture(Display::ITexture &src)
{
    Display::NCursesTexture ncursesTexture = dynamic_cast<Display::NCursesTexture &>(src);

    this->c = ncursesTexture.getChar();
    this->texture = src;
}

void Display::NCursesSprite::move(const Vector2f &offset)
{
    this->position.x += offset.x;
    this->position.y += offset.y;
}

char &Display::NCursesSprite::getChar()
{
    return this->c;
}
