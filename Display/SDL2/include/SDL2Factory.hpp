/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2Factory.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "SDL2Exception.hpp"
#include "SDL2Window.hpp"
#include "SDL2Sprite.hpp"
#include "SDL2Texture.hpp"
#include "SDL2Font.hpp"
#include "SDL2Text.hpp"
#include "SDL2Clock.hpp"
#include <memory>

namespace Display {
    class SDL2Factory : public IFactory {
        public:
            SDL2Factory() = default;
            ~SDL2Factory() override;
            std::unique_ptr<Display::IWindow> createWindow(
                const std::string &title,
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
                std::string const &texturePath
            ) override;
            std::unique_ptr<Display::IFont> createFont(
                std::string const &fontPath
            ) override;
            std::unique_ptr<Display::IText> createText(
                const std::string &text,
                const Display::IFont &font,
                const Display::Color &color,
                const Display::Vector2f &position
            ) override;
            std::unique_ptr<Display::IClock> createClock() override;

        private:
            Display::SDL2Window *window{nullptr};
    };
}
