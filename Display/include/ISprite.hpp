/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ISprite
*/

#pragma once

#include "ITexture.hpp"
#include "IntRect.hpp"
#include "Vector2f.hpp"
#include <memory>

namespace Display {
    class ISprite {
        public:
            virtual ~ISprite() = default;
            virtual Display::IntRect getRect() = 0;
            virtual void setRect(const Display::IntRect &rect) = 0;
            virtual Display::Vector2f getPosition() = 0;
            virtual void setPosition(const Display::Vector2f &position) = 0;
            virtual void setTexture(Display::ITexture &texture) = 0;
            virtual void move(const Display::Vector2f &offset) = 0;
    };
};
