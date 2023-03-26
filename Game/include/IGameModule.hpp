/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IGameModule
*/

#pragma once
#include "IWindow.hpp"
#include "ISprite.hpp"
#include "ITexture.hpp"
#include <string>
#include <memory>

namespace Game {
    class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual void setFunctions(
            std::unique_ptr<Display::IWindow> (*)(),
            std::unique_ptr<Display::ISprite> (*)(),
            std::unique_ptr<Display::ITexture> (*)()
        ) = 0;
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
    };
}
