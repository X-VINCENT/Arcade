/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ITexture
*/

#pragma once
#include <memory>
#include "IVector2f.hpp"

namespace Display {
    class ITexture {
        public:
            virtual ~ITexture() = default;
            virtual void load(char c, std::string const &fpath) = 0;
    };
    extern "C" std::unique_ptr<ITexture> createTexture();
};
