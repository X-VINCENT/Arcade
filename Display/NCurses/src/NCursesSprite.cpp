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

void Display::NCursesSprite::create(
    std::unique_ptr<ITexture> src_texture,
    const IIntRect &src_rect,
    const IVector2f &src_position
)
{
    Display::NCursesTexture ncursesTexture =
            dynamic_cast<Display::NCursesTexture &>(*texture);

    // !!Character not set
    this->c = ncursesTexture.getNCursesTexture();
    this->texture = std::move(texture);
    this->rect = src_rect;
    this->position = src_position;
}

Display::IIntRect Display::NCursesSprite::getRect()
{
    return this->rect;
}

void Display::NCursesSprite::setRect(const Display::IIntRect &src_rect)
{
    this->rect = src_rect;
}

Display::IVector2f Display::NCursesSprite::getPosition()
{
    return this->position;
}

void Display::NCursesSprite::setPosition(const Display::IVector2f &position)
{
    this->position = position;
}

std::unique_ptr<Display::ITexture> Display::NCursesSprite::getTexture()
{
    return std::move(this->texture);
}

void Display::NCursesSprite::setTexture(std::unique_ptr<Display::ITexture>
src_texture)
{
    Display::NCursesTexture ncursesTexture =
            dynamic_cast<Display::NCursesTexture &>(*src_texture);

    this->c = ncursesTexture.getNCursesTexture();
    this->texture = std::move(src_texture);
}

void Display::NCursesSprite::move(const IVector2f &offset)
{
    this->position.x = this->position.x + offset.x;
    this->position.y = this->position.y + offset.y;
}

extern "C" std::unique_ptr<Display::ISprite> Display::createSprite()
{
    return std::make_unique<Display::NCursesSprite>();
}
