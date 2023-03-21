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
    class SFMLIntRect : public IIntRect {
        public:
            SFMLIntRect() = default;
            ~SFMLIntRect();
            void create(int left, int top, int width, int height) override;
            int getLeft() override;
            void setLeft(int left) override;
            int getTop() override;
            void setTop(int top) override;
            int getWidth() override;
            void setWidth(int width) override;
            int getHeight() override;
            void setHeight(int height) override;
            sf::IntRect getSFMLIntRect() const;

        private:
            sf::IntRect rect;
    };
}
