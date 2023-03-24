/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IGameModule
*/

#pragma once
#include <string>

namespace Game {
    class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
    };
}
