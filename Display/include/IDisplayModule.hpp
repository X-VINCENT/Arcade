/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IDisplayModule
*/

#pragma once
#include <string>

class IDisplayModule {
	public:
        virtual ~IDisplayModule() = default;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void destroy() = 0;
};
