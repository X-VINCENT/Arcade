/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLSprite
*/

#include "SFMLSprite.hpp"
#include "SFMLTexture.hpp"
#include "SFMLIntRect.hpp"
#include "SFMLVector2f.hpp"

Display::SFMLSprite::~SFMLSprite()
{
}

void Display::SFMLSprite::create(
    std::unique_ptr<Display::ITexture> &texture,
    std::unique_ptr<Display::IIntRect> &rect,
    std::unique_ptr<Display::IVector2f> &position
)
{
    Display::SFMLTexture* sfmlTexture = dynamic_cast<Display::SFMLTexture*>(texture.get());
    Display::SFMLIntRect* sfmlRect = dynamic_cast<Display::SFMLIntRect*>(rect.get());
    Display::SFMLVector2f* sfmlPosition = dynamic_cast<Display::SFMLVector2f*>(position.get());
    if (sfmlTexture == nullptr || sfmlRect == nullptr || sfmlPosition == nullptr)
        return;

    sf::Texture sfTexture = sfmlTexture->getSFMLTexture();
    sf::IntRect sfRect = sfmlRect->getSFMLIntRect();
    sf::Vector2f sfPosition = sfmlPosition->getSFMLVector2f();

    this->sprite->setTexture(sfTexture);
    this->sprite->setTextureRect(sfRect);
    this->sprite->setPosition(sfPosition);
    this->texture = std::move(texture);
    this->rect = std::move(rect);
    this->position = std::move(position);
}

std::unique_ptr<Display::IIntRect> Display::SFMLSprite::getRect()
{
    return std::move(this->rect);
}

void Display::SFMLSprite::setRect(std::unique_ptr<Display::IIntRect> &rect)
{
    Display::SFMLIntRect* sfmlRect = dynamic_cast<Display::SFMLIntRect*>(rect.get());
    if (sfmlRect == nullptr)
        return;
    sf::IntRect sfRect = sfmlRect->getSFMLIntRect();
    this->sprite->setTextureRect(sfRect);
    this->rect = std::move(rect);
}

std::unique_ptr<Display::IVector2f> Display::SFMLSprite::getPosition()
{
}

void Display::SFMLSprite::setPosition(std::unique_ptr<Display::IVector2f> &position)
{
    Display::SFMLVector2f* sfmlPosition = dynamic_cast<Display::SFMLVector2f*>(position.get());
    if (sfmlPosition == nullptr)
        return;
    sf::Vector2f sfPosition = sfmlPosition->getSFMLVector2f();
    this->sprite->setPosition(sfPosition);
    this->position = std::move(position);
}

std::unique_ptr<Display::ITexture> Display::SFMLSprite::getTexture()
{
    return std::move(this->texture);
}

void Display::SFMLSprite::setTexture(std::unique_ptr<Display::ITexture> &texture)
{
    Display::SFMLTexture* sfmlTexture = dynamic_cast<Display::SFMLTexture*>(texture.get());
    if (sfmlTexture == nullptr)
        return;
    sf::Texture sfTexture = sfmlTexture->getSFMLTexture();
    this->sprite->setTexture(sfTexture);
    this->texture = std::move(texture);
}

void Display::SFMLSprite::move(std::unique_ptr<Display::IVector2f> &offset)
{
    Display::SFMLVector2f* sfmlOffset = dynamic_cast<Display::SFMLVector2f*>(offset.get());
    if (sfmlOffset == nullptr)
        return;
    sf::Vector2f sfOffset = sfmlOffset->getSFMLVector2f();
    this->sprite->move(sfOffset);
    this->position->setX(this->position->getX() + offset->getX());
    this->position->setY(this->position->getY() + offset->getY());
}

extern "C" std::unique_ptr<Display::ISprite> createSprite()
{
    return std::make_unique<Display::SFMLSprite>();
}
