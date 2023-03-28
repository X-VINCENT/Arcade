/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesRenderer
*/

#pragma once
#include "IRenderer.hpp"
#include "IWindow.hpp"

namespace Display {
    class NCursesRenderer : public IRenderer {
        public:
            NCursesRenderer() = default;
            ~NCursesRenderer() override;
            void create(std::unique_ptr<Display::IWindow> &window) override;
            std::unique_ptr<Display::IRenderer> clone() const override;
    };
};
