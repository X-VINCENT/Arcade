/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLIntRect
*/

#pragma once
#include "IIntRect.hpp"
#include "SFML/Graphics.hpp"

namespace Display {
    sf::IntRect toSfIntRect(const IIntRect &);
    IIntRect toIIntRect(const sf::IntRect &);
}
