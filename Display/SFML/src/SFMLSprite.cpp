/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLSprite
*/

#include "SFMLSprite.hpp"
#include "ITexture.hpp"
#include "SFMLTexture.hpp"

#define SFML_RATIO 10

Display::SFMLSprite::SFMLSprite(
    Display::ITexture &src_texture,
    const Display::IntRect &src_rect,
    const Display::Vector2f &src_position
)
{
    Display::SFMLTexture sfmlTexture = dynamic_cast<Display::SFMLTexture &>(src_texture);

    this->texture = sfmlTexture.getSFTexture();
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect({
        src_rect.left * SFML_RATIO,
        src_rect.top * SFML_RATIO,
        src_rect.width * SFML_RATIO,
        src_rect.height * SFML_RATIO
    });
    this->sprite.setPosition({
        src_position.x,
        src_position.y
    });
    this->position = src_position;
    this->rect = src_rect;
}

Display::SFMLSprite::~SFMLSprite()
{
}

Display::IntRect Display::SFMLSprite::getRect()
{
    return this->rect;
}

void Display::SFMLSprite::setRect(const Display::IntRect &src)
{
    this->sprite.setTextureRect({
        src.left * SFML_RATIO,
        src.top * SFML_RATIO,
        src.width * SFML_RATIO,
        src.height * SFML_RATIO
    });
    this->rect = src;
}

void Display::SFMLSprite::setPosition(const Display::Vector2f &position)
{
    this->sprite.setPosition({
        position.x,
        position.y
    });
    this->position = position;
}

Display::Vector2f Display::SFMLSprite::getPosition()
{
    return this->position;
}

void Display::SFMLSprite::setTexture(Display::ITexture &src)
{
    Display::SFMLTexture sfmlTexture = dynamic_cast<Display::SFMLTexture &>(src);

    this->texture = sfmlTexture.getSFTexture();
    this->sprite.setTexture(this->texture);
}

void Display::SFMLSprite::move(const Display::Vector2f &offset)
{
    this->sprite.move({
        offset.x,
        offset.y
    });
    this->setPosition({
        this->position.x + offset.x,
        this->position.y + offset.y
    });
}

sf::Sprite &Display::SFMLSprite::getSFSprite()
{
    return this->sprite;
}
