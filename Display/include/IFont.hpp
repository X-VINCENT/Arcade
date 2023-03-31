/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ISprite
*/

#pragma once
#include <string>

namespace Display {
    class IFont {
        public:
            virtual ~IFont() = default;
            virtual void setFont(const std::string &fontPath) = 0;
    };
};
