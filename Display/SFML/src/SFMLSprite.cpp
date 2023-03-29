/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLSprite
*/

#include "SFMLSprite.hpp"
#include "ITexture.hpp"
#include "SFMLTexture.hpp"
#include "SFMLIntRect.hpp"
#include "SFMLVector2f.hpp"

Display::SFMLSprite::SFMLSprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    Display::SFMLTexture sfmlTexture = dynamic_cast<Display::SFMLTexture &>(src_texture);

    this->texture = sfmlTexture.getSFMLTexture();
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(toSfIntRect(src_rect));
    this->sprite.setPosition(toSfVector2f(src_position));
    this->position = toSfVector2f(src_position);
    this->rect = toSfIntRect(src_rect);
}

Display::SFMLSprite::~SFMLSprite()
{
}

Display::IntRect Display::SFMLSprite::getRect()
{
    return toIIntRect(this->rect);
}

void Display::SFMLSprite::setRect(const Display::IntRect &src)
{
    this->sprite.setTextureRect(toSfIntRect(src));
    this->rect = toSfIntRect(src);
}

void Display::SFMLSprite::setPosition(const Display::Vector2f &position)
{
    this->sprite.setPosition(toSfVector2f(position));
    this->position = toSfVector2f(position);
}

Display::Vector2f Display::SFMLSprite::getPosition()
{
    return toIVector2f(this->position);
}

void Display::SFMLSprite::setTexture(Display::ITexture &src)
{
    Display::SFMLTexture sfmlTexture = dynamic_cast<Display::SFMLTexture &>(src);

    this->texture = sfmlTexture.getSFMLTexture();
    this->sprite.setTexture(this->texture);
}

void Display::SFMLSprite::move(const Display::Vector2f &offset)
{
    this->sprite.move(toSfVector2f(offset));
    this->setPosition(this->position + toSfVector2f(offset));
}

void Display::SFMLSprite::setPosition(const sf::Vector2f &src)
{
    this->position = src;
}

sf::IntRect &Display::SFMLSprite::getSfRect()
{
    return this->rect;
}

sf::Sprite &Display::SFMLSprite::getSfSprite()
{
    return this->sprite;
}
