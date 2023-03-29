/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLIntRect
*/

#pragma once
#include "IntRect.hpp"
#include "SFML/Graphics.hpp"

namespace Display {
    sf::IntRect toSfIntRect(const IntRect &);
    IntRect toIIntRect(const sf::IntRect &);
}
