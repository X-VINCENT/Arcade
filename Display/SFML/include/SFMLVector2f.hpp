/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#pragma once
#include "IVector2f.hpp"
#include "SFML/Graphics.hpp"

namespace Display {
    class SFMLVector2f : public IVector2f {
        public:
            SFMLVector2f() = default;
            ~SFMLVector2f();
            void create(float x, float y) override;
            float getX() override;
            void setX(float x) override;
            float getY() override;
            void setY(float y) override;
            sf::Vector2f getSFMLVector2f() const;

        private:
            sf::Vector2f vector;
    };
}
