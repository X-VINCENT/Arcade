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
            SFMLWindow(
                const std::string &title,
                int framerateLimit,
                int width,
                int height);
            ~SFMLWindow();
            Display::Event getEvent() override;
            void setTitle(const std::string &title) override;
            bool isOpen() override;
            void clear() override;
            void draw(Display::ISprite &sprite) override;
            void display() override;
            void close() override;

        protected:
        private:
            sf::RenderWindow window;
    };
};
