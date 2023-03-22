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
            char c;
            std::unique_ptr<Display::IIntRect> rect;
            std::unique_ptr<Display::IVector2f> position;
            std::unique_ptr<Display::ITexture> texture;
    };
}
