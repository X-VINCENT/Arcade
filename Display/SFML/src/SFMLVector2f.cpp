/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#include "SFMLVector2f.hpp"

sf::Vector2f Display::toSfVector2f(const Display::IVector2f &src)
{
    sf::Vector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;

}

Display::IVector2f Display::toIVector2f(const sf::Vector2f &src)
{
    Display::IVector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;
}
