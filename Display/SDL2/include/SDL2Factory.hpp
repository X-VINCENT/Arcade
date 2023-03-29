/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2Factory.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "SDL2Window.hpp"
#include "SDL2Sprite.hpp"
#include "SDL2Texture.hpp"
#include <memory>

namespace Display {
    class SDL2Factory : public IFactory {
        public:
            SDL2Factory() = default;
            ~SDL2Factory() override;
            std::unique_ptr<Display::IWindow> createWindow(
                std::string const &title,
                int framerate,
                int width,
                int height
            ) override;
            std::unique_ptr<Display::ISprite> createSprite(
                Display::ITexture &src_texture,
                const Display::IntRect &src_rect,
                const Display::Vector2f &src_position
            ) override;
            std::unique_ptr<Display::ITexture> createTexture(
                char c,
                std::string const &fpath
            ) override;
        private:
            Display::SDL2Window window = Display::SDL2Window();
    };
}
