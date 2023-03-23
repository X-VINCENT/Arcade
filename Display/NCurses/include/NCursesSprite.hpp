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
            NCursesSprite() = default;
            ~NCursesSprite();
            void create(
                std::unique_ptr<ITexture> texture,
                const IIntRect &rect,
                const IVector2f &position
            ) override;
            Display::IIntRect getRect() override;
            void setRect(const Display::IIntRect &rect) override;
            Display::IVector2f getPosition() override;
            void setPosition(const Display::IVector2f &position) override;
            std::unique_ptr<Display::ITexture> getTexture() override;
            void setTexture(std::unique_ptr<Display::ITexture> texture) override;
            void move(const IVector2f &offset) override;

        private:
            char c;
            Display::IIntRect rect;
            Display::IVector2f position;
            std::unique_ptr<Display::ITexture> texture;
    };
}
