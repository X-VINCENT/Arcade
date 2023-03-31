/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IWindow
*/

#pragma once
#include "Event.hpp"
#include "ISprite.hpp"
#include "IText.hpp"
#include <memory>

namespace Display {
    class IWindow {
        public:
            virtual ~IWindow() = default;
            virtual Display::Event getEvent() = 0;
            virtual void setTitle(const std::string &title) = 0;
            virtual bool isOpen() = 0;
            virtual void clear() = 0;
            virtual void draw(Display::ISprite &sprite) = 0;
            virtual void draw(Display::IText &text) = 0;
            virtual void display() = 0;
            virtual void close() = 0;
    };
};
