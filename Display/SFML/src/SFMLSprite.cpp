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

Display::SFMLSprite::~SFMLSprite()
{
}

void Display::SFMLSprite::create(
        std::unique_ptr<Display::ITexture> src_texture,
        const Display::IIntRect &src_rect,
        const Display::IVector2f &src_position
)
{
    Display::SFMLTexture sfmlTexture = dynamic_cast<Display::SFMLTexture &>(*src_texture);

    this->texture = sfmlTexture.getSFMLTexture();
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(toSfIntRect(src_rect));
    this->sprite.setPosition(toSfVector2f(src_position));
    this->position = toSfVector2f(src_position);
    this->rect = toSfIntRect(src_rect);
}

Display::IIntRect Display::SFMLSprite::getRect()
{
    return toIIntRect(this->rect);
}

void Display::SFMLSprite::setRect(const Display::IIntRect &src)
{
    this->sprite.setTextureRect(toSfIntRect(src));
    this->rect = toSfIntRect(src);
}
void Display::SFMLSprite::setPosition(
        const Display::IVector2f &position)
{
    this->sprite.setPosition(toSfVector2f(position));
    this->position = toSfVector2f(position);
}

Display::IVector2f Display::SFMLSprite::getPosition()
{
    return toIVector2f(this->position);
}

std::unique_ptr<Display::ITexture> Display::SFMLSprite::getTexture()
{
    std::unique_ptr<Display::SFMLTexture> text =
            std::make_unique<Display::SFMLTexture>();

    text->getSFMLTexture() = this->texture;
    return text;
}

void Display::SFMLSprite::setTexture(std::unique_ptr<Display::ITexture> src)
{
    Display::SFMLTexture text = dynamic_cast<Display::SFMLTexture &>(*src);
    this->sprite.setTexture(text.getSFMLTexture());
}

void Display::SFMLSprite::move(const Display::IVector2f &offset)
{
    this->sprite.move(toSfVector2f(offset));
    this->setPosition(this->position + toSfVector2f(offset));
}

void Display::SFMLSprite::create(const Display::SFMLSprite &src)
{
    this->position = src.position;
    this->texture = src.texture;
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

extern "C" std::unique_ptr<Display::ISprite> createSprite()
{
    return std::make_unique<Display::SFMLSprite>();
}
