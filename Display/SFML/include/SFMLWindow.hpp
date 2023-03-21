/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLWindow
*/

#pragma once

#include "IWindow.hpp"
#include "IGameModule.hpp"
#include <ncurses.h>
#include <memory>

namespace Display {
    class SFMLWindow : public IWindow {
    public:

        SFMLWindow() = default;
        SFMLWindow(std::string const &title, int framerateLimit,
                int width, int height);
        ~SFMLWindow() override;
        void create(std::string const &title, int framerateLimit,
                int width, int height) override;
        void getFramerateLimit() override;
        void setFramerateLimit(int framerateLimit) override;
        void getSize() override;
        void setSize(int width, int height) override;
        void getPosition() override;
        void setPosition(int x, int y) override;
        void clear() override;
        void draw() override;
        void destroy() override;

    protected:
    private:
        WINDOW *_window;
    };
};
