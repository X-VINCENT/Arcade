/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IWindow
*/

#pragma once
#include "IRenderer.hpp"
#include "IDisplayModule.hpp"
#include "IEvent.hpp"
#include "ISprite.hpp"
#include <memory>

namespace Display {
    class IRenderer;
    class ISprite;
    class IWindow {
        public:
            virtual ~IWindow() = default;
            virtual Display::IEvent &getEvent() = 0;
            virtual std::string &getTitle() = 0;
            virtual void setTitle(std::string const &title) = 0;
            virtual bool isOpen() = 0;
            virtual void clear() = 0;
            virtual void draw(Display::ISprite &sprite) = 0;
            virtual void display() = 0;
            virtual void close() = 0;
    };
    extern "C" std::unique_ptr<IWindow> createWindow();
};
