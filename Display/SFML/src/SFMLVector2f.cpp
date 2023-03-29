/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#include "SFMLVector2f.hpp"

sf::Vector2f Display::toSfVector2f(const Display::Vector2f &src)
{
    sf::Vector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;

}

Display::Vector2f Display::toIVector2f(const sf::Vector2f &src)
{
    Display::Vector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;
}
