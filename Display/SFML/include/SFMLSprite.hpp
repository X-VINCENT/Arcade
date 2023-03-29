/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLSprite
*/

#pragma once

#include "ISprite.hpp"
#include "SFMLTexture.hpp"
#include "SFMLIntRect.hpp"
#include "SFMLVector2f.hpp"
#include "SFML/Graphics.hpp"
#include <memory>

namespace Display {
    class SFMLSprite : public ISprite {
        public:
            SFMLSprite(
                    Display::ITexture &texture,
                    const IntRect &rect,
                    const Vector2f &position);
            ~SFMLSprite() override;
            Display::IntRect getRect() override;
            sf::IntRect &getSfRect();
            void setRect(const Display::IntRect &rect) override;
            Display::Vector2f getPosition() override;
            void setPosition(const Display::Vector2f &position) override;
            void setPosition(const sf::Vector2f &);
            void setTexture(Display::ITexture &texture) override;
            void move(const Vector2f &offset) override;
            sf::Sprite &getSfSprite();

        private:
            sf::Sprite sprite;
            sf::Texture texture;
            sf::IntRect rect;
            sf::Vector2f position;
    };
}
