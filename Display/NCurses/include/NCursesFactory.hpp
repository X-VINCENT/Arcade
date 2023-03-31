/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesFactory.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "NCursesWindow.hpp"
#include "NCursesSprite.hpp"
#include "NCursesTexture.hpp"
#include <memory>

namespace Display {
    class NCursesFactory : public IFactory {
        public:
            NCursesFactory() = default;
            ~NCursesFactory() override;
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
    };
}
