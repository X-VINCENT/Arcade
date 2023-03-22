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
    std::unique_ptr<ITexture> &texture,
    std::unique_ptr<IIntRect> &rect,
    std::unique_ptr<IVector2f> &position
)
{
    Display::NCursesTexture* ncursesTexture = dynamic_cast<Display::NCursesTexture*>(texture.get());
    if (ncursesTexture == nullptr)
        return;
    char c = ncursesTexture->getNCursesTexture();

    this->c = c;
    this->texture = std::move(texture);
    this->rect = std::move(rect);
    this->position = std::move(position);
}

std::unique_ptr<Display::IIntRect> Display::NCursesSprite::getRect()
{
    return std::move(this->rect);
}

void Display::NCursesSprite::setRect(std::unique_ptr<Display::IIntRect> &rect)
{
    this->rect = std::move(rect);
}

std::unique_ptr<Display::IVector2f> Display::NCursesSprite::getPosition()
{
    return std::move(this->position);
}

void Display::NCursesSprite::setPosition(std::unique_ptr<Display::IVector2f> &position)
{
    this->position = std::move(position);
}

std::unique_ptr<Display::ITexture> Display::NCursesSprite::getTexture()
{
    return std::move(this->texture);
}

void Display::NCursesSprite::setTexture(std::unique_ptr<Display::ITexture> &texture)
{
    Display::NCursesTexture* ncursesTexture = dynamic_cast<Display::NCursesTexture*>(texture.get());
    if (ncursesTexture == nullptr)
        return;
    char c = ncursesTexture->getNCursesTexture();

    this->c = c;
    this->texture = std::move(texture);
}

void Display::NCursesSprite::move(std::unique_ptr<IVector2f> &offset)
{
    this->position->setX(this->position->getX() + offset->getX());
    this->position->setY(this->position->getY() + offset->getY());
}

extern "C" std::unique_ptr<Display::ISprite> Display::createSprite()
{
    return std::make_unique<Display::NCursesSprite>();
}
