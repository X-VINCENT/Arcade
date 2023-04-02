/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLText
*/

#include <SFML/Graphics.hpp>
#include "SFMLText.hpp"
#include "SFMLFont.hpp"

sf::Color colorToSFColor(const Display::Color &color)
{
    switch (color) {
        case Display::Color::BLACK:
            return {0, 0, 0};
        case Display::Color::WHITE:
            return {255, 255, 255};
        case Display::Color::RED:
            return {255, 0, 0};
        case Display::Color::GREEN:
            return {0, 255, 0};
        case Display::Color::BLUE:
            return {0, 0, 255};
        case Display::Color::YELLOW:
            return {255, 255, 0};
        case Display::Color::MAGENTA:
            return {255, 0, 255};
        case Display::Color::CYAN:
            return {0, 255, 255};
        default:
            return {255, 255, 255};
    }
}

Display::SFMLText::SFMLText(
    const std::string &text,
    const Display::IFont &font,
    const Display::Color &color,
    const Display::Vector2f &position
)
{
    Display::SFMLFont sfmlFont = dynamic_cast<const Display::SFMLFont &>(font);

    this->font = sfmlFont.getSFFont();
    this->fontSize = sfmlFont.getFontSize();
    this->color = colorToSFColor(color);
    this->text.setFont(this->font);
    this->text.setCharacterSize(this->fontSize);
    this->text.setString(text);
    this->text.setFillColor(colorToSFColor(color));
    this->text.setPosition(position.x, position.y);
    this->position = position;
}

Display::SFMLText::~SFMLText()
{
}

void Display::SFMLText::setText(const std::string &src)
{
    this->text.setString(src);
}

void Display::SFMLText::setFont(const Display::IFont &src)
{
    Display::SFMLFont sfmlFont = dynamic_cast<const Display::SFMLFont &>(src);

    this->font = sfmlFont.getSFFont();
    this->fontSize = sfmlFont.getFontSize();
    this->text.setFont(this->font);
    this->text.setCharacterSize(this->fontSize);
}

void Display::SFMLText::setColor(const Display::Color &src)
{
    this->color = colorToSFColor(src);
}

void Display::SFMLText::setPosition(const Display::Vector2f &src)
{
    this->position = src;
}

Display::Vector2f Display::SFMLText::getPosition() const
{
    return this->position;
}

void Display::SFMLText::move(const Display::Vector2f &offset)
{
    this->position.x += offset.x;
    this->position.y += offset.y;
}

sf::Text &Display::SFMLText::getSFText()
{
    return this->text;
}

int Display::SFMLText::getFontSize() const
{
    return this->fontSize;
}
