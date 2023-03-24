/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#pragma once
#include "IVector2f.hpp"
#include "SFML/Graphics.hpp"

namespace Display {
    sf::Vector2f toSfVector2f(const IVector2f &);
    IVector2f toIVector2f(const sf::Vector2f &);
}
