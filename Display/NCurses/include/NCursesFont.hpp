/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesFont
*/

#pragma once
#include "IFont.hpp"

namespace Display {
    class NCursesFont : public IFont {
        public:
            NCursesFont();
            ~NCursesFont() override;
            void setFont(const std::string &fontPath) override;
    };
};
