/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLWindow
*/

#pragma once
#include "IWindow.hpp"
#include "IEvent.hpp"
#include <SFML/Graphics.hpp>

namespace Display {
    class SFMLWindow : public IWindow {
        public:
            SFMLWindow() = default;
            SFMLWindow(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            );
            ~SFMLWindow() override;
            void create(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            ) override;
            IEvent getEvents() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;

        protected:
        private:
            sf::RenderWindow window;
            std::string title;
    };
};
