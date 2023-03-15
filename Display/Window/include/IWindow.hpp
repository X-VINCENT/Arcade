/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IWindow
*/

#pragma once
#include "IDisplayModule.hpp"

class IWindow : public IDisplayModule {
    public:
        virtual ~IWindow() = default;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void destroy() = 0;
};
