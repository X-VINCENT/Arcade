/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesSprite
*/

#pragma once
#include "ISprite.hpp"
#include <memory>

namespace Display {
    class NCursesSprite : public ISprite {
        public:
            NCursesSprite(
                std::unique_ptr<ITexture> texture,
                const IntRect &rect,
                const Vector2f &position
            );
            ~NCursesSprite() override;
            Display::IntRect getRect() override;
            void setRect(const Display::IntRect &rect) override;
            Display::Vector2f getPosition() override;
            void setPosition(const Display::Vector2f &position) override;
            const Display::ITexture &getTexture() override;
            void setTexture(Display::ITexture &texture) override;
            void move(const Vector2f &offset) override;

        private:
            char c;
            Display::IntRect rect;
            Display::Vector2f position;
            Display::ITexture &texture;
    };
}
