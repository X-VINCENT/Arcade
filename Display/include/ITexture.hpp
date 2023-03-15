/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ITexture
*/

#pragma once
#include "IDisplayModule.hpp"

class ITexture : public IDisplayModule {
    public:
        virtual ~ITexture() = default;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void destroy() = 0;
};
