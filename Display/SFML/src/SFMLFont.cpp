/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLFont
*/

#include "SFMLFont.hpp"
#include "SFMLException.hpp"
#include <iostream>

#define DEFAULT_SFML_FONT_SIZE 32

Display::SFMLFont::SFMLFont(std::string const &fontPath)
{
    try {
        if (!this->font.loadFromFile(fontPath))
            throw SFMLException("Can't load font " + fontPath);
    } catch (SFMLException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Display::SFMLFont::~SFMLFont()
{
}

void Display::SFMLFont::setFont(const std::string &fontPath)
{
    try {
        if (!this->font.loadFromFile(fontPath))
            throw SFMLException("Can't load font " + fontPath);
    } catch (SFMLException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

sf::Font &Display::SFMLFont::getSFFont()
{
    return this->font;
}

int Display::SFMLFont::getFontSize() const
{
    return DEFAULT_SFML_FONT_SIZE;
}
