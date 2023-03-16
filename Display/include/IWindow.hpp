/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IWindow
*/

#pragma once

#include "IDisplayModule.hpp"
#include <memory>

namespace Display {

    class IWindow {
    public:
        virtual ~IWindow() = default;

        virtual void create(std::string const &title, int framerateLimit,
                int width, int height) = 0;

        virtual void getFramerateLimit() = 0;

        virtual void setFramerateLimit(int framerateLimit) = 0;

        virtual void getSize() = 0;

        virtual void setSize(int width, int height) = 0;

        virtual void getPosition() = 0;

        virtual void setPosition(int x, int y) = 0;

        virtual void clear() = 0;

        virtual void draw() = 0;

        virtual void destroy() = 0;
    };
    extern "C" std::unique_ptr<IWindow> createWindow();
};
