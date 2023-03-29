/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLWindow
*/

#pragma once
#include "IWindow.hpp"
#include <SFML/Graphics.hpp>

namespace Display {
    class SFMLWindow : public IWindow {
        public:
            SFMLWindow() = default;
            ~SFMLWindow();
            void create(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            ) override;
            void setRenderer(std::unique_ptr<Display::IRenderer> renderer) override;
            std::unique_ptr<Display::IEvent> getEvent() override;
            std::string &getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw(std::unique_ptr<Display::ISprite> &sprite) override;
            void display() override;
            void close() override;

        protected:
        private:
            sf::RenderWindow window;
            std::string title;
    };
};
