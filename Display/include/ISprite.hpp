/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ISprite
*/

#pragma once

#include "IDisplayModule.hpp"
#include "ITexture.hpp"
#include "IIntRect.hpp"
#include "IVector2f.hpp"
#include <memory>

namespace Display {
    class ISprite {
        public:
            virtual ~ISprite() = default;
            virtual void create(
                    std::unique_ptr<ITexture> texture,
                    const IIntRect &rect,
                    const IVector2f &position
            ) = 0;
            virtual Display::IIntRect getRect() = 0;
            virtual void setRect(const Display::IIntRect &rect) = 0;
            virtual Display::IVector2f getPosition() = 0;
            virtual void setPosition(const Display::IVector2f &position) = 0;
            virtual std::unique_ptr<Display::ITexture> getTexture() = 0;
            virtual void setTexture(std::unique_ptr<Display::ITexture> texture) = 0;
            virtual void move(const Display::IVector2f &offset) = 0;
    };

    extern "C" std::unique_ptr<ISprite> createSprite();
};
