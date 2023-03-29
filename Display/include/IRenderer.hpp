/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IRenderer
*/

#pragma once
#include <memory>
#include "IWindow.hpp"

namespace Display {
    class IWindow;
    class IRenderer {
        public:
            virtual ~IRenderer() = default;
            virtual void create(std::unique_ptr<Display::IWindow> &window) = 0;
            virtual std::unique_ptr<Display::IRenderer> clone() const = 0;
    };
    extern "C" std::unique_ptr<IRenderer> createRenderer();
};
