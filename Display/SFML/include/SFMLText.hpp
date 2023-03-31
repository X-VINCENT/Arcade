/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLText
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "IText.hpp"
#include "Color.hpp"
#include "IFont.hpp"
#include "Vector2f.hpp"

namespace Display {
    class SFMLText : public IText {
        public:
            SFMLText(
                const std::string &text,
                const Display::IFont &font,
                const Display::Color &color,
                const Display::Vector2f &position
            );
            ~SFMLText() override;
            void setText(const std::string &text) override;
            void setFont(const Display::IFont &font) override;
            void setColor(const Display::Color &color) override;
            void setPosition(const Display::Vector2f &position) override;
            Display::Vector2f getPosition() const override;
            void move(const Display::Vector2f &offset) override;
            sf::Text &getSFText();

        private:
            sf::Text text;
            sf::Font font;
            sf::Color color;
            Display::Vector2f position;
    };
};
