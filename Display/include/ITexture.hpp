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
    };
    extern "C" std::unique_ptr<ITexture> createTexture();
};
