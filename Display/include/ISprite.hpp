/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** ISprite
*/

#pragma once
#include "IDisplayModule.hpp"

namespace Display {
    class ISprite : public IDisplayModule {
    public:
        virtual ~ISprite() = default;

        virtual void create() = 0;

        virtual void update() = 0;

        virtual void destroy() = 0;
    };
};
