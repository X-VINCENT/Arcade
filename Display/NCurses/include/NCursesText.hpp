/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesText
*/

#pragma once
#include "IText.hpp"
#include "Color.hpp"
#include "IFont.hpp"
#include "Vector2f.hpp"

namespace Display {
    class NCursesText : public IText {
        public:
            NCursesText(
                const std::string &text,
                const Display::Color &color,
                const Display::Vector2f &position
            );
            ~NCursesText() override;
            void setText(const std::string &text) override;
            void setFont(const Display::IFont &font) override;
            void setColor(const Display::Color &color) override;
            void setPosition(const Display::Vector2f &position) override;
            Display::Vector2f getPosition() const override;
            void move(const Display::Vector2f &offset) override;
            std::string &getText();
            Display::Color getColor() const;

        private:
            std::string text;
            Display::Color color;
            Display::Vector2f position;
    };
};
