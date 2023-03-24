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
        SFMLSprite() = default;
        ~SFMLSprite() override;
        void create(
                std::unique_ptr<ITexture> texture,
                const IIntRect &rect,
                const IVector2f &position
        ) override;
        void create(const SFMLSprite &);
        Display::IIntRect getRect() override;
        sf::IntRect &getSfRect();
        void setRect(const Display::IIntRect &rect)
        override;
        Display::IVector2f getPosition() override;
        void setPosition(const Display::IVector2f
        &position) override;
        void setPosition(const sf::Vector2f &);
        std::unique_ptr<Display::ITexture> getTexture() override;
        void setTexture(std::unique_ptr<Display::ITexture> texture) override;
        void move(const IVector2f &offset) override;

    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::IntRect rect;
        sf::Vector2f position;
    };
}
