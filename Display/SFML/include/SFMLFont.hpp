/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLFont
*/

#pragma once
#include "IFont.hpp"
#include <SFML/Graphics.hpp>

namespace Display {
    class SFMLFont : public IFont {
        public:
            SFMLFont(const std::string &fontPath);
            ~SFMLFont();
            void setFont(const std::string &fontPath) override;
            sf::Font &getSFFont();

        private:
            sf::Font font;
    };
};
