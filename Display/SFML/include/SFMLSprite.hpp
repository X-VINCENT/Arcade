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
            ~SFMLSprite();
            void create(
                std::unique_ptr<ITexture> &texture,
                std::unique_ptr<IIntRect> &rect,
                std::unique_ptr<IVector2f> &position
            ) override;
            std::unique_ptr<Display::IIntRect> getRect() override;
            void setRect(std::unique_ptr<Display::IIntRect> &rect) override;
            std::unique_ptr<Display::IVector2f> getPosition() override;
            void setPosition(std::unique_ptr<Display::IVector2f> &position) override;
            std::unique_ptr<Display::ITexture> getTexture() override;
            void setTexture(std::unique_ptr<Display::ITexture> &texture) override;
            void move(std::unique_ptr<IVector2f> &offset) override;

        private:
            std::unique_ptr<sf::Sprite> sprite;
            std::unique_ptr<Display::ITexture> texture;
            std::unique_ptr<Display::IIntRect> rect;
            std::unique_ptr<Display::IVector2f> position;
    };
}
