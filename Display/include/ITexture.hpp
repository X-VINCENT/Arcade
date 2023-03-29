/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ITexture
*/

#pragma once
#include <memory>
#include "IRenderer.hpp"

namespace Display {
    class IRenderer;
    class ITexture {
        public:
            virtual ~ITexture() = default;
            virtual void load(char c, std::string const &fpath, std::unique_ptr<Display::IRenderer> renderer) = 0;
            virtual std::unique_ptr<Display::ITexture> clone() const = 0;
    };
    extern "C" std::unique_ptr<ITexture> createTexture();
};
