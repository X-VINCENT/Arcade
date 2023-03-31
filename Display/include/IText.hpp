/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ISprite
*/

#pragma once
#include "Color.hpp"
#include "IFont.hpp"
#include "Vector2f.hpp"

namespace Display {
    class IText {
        public:
            virtual ~IText() = default;
            virtual void setText(const std::string &text) = 0;
            virtual void setFont(const Display::IFont &font) = 0;
            virtual void setColor(const Display::Color &color) = 0;
            virtual void setPosition(const Display::Vector2f &position) = 0;
            virtual Display::Vector2f getPosition() const = 0;
            virtual void move(const Display::Vector2f &offset) = 0;
    };
};
