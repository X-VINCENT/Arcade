/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IFactory
*/

#pragma once

#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include "IWindow.hpp"
#include "ISprite.hpp"
#include "ITexture.hpp"

namespace Display {
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual std::unique_ptr<Display::IWindow> createWindow(
                std::string const &title,
                int framerate,
                int width,
                int height
            ) = 0;
            virtual std::unique_ptr<Display::ISprite> createSprite(
                Display::ITexture &src_texture,
                const Display::IntRect &src_rect,
                const Display::Vector2f &src_position
            ) = 0;
            virtual std::unique_ptr<Display::ITexture> createTexture(
                char c,
                std::string const &fpath
            ) = 0;
    };
};
