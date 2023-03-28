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
#include "IRenderer.hpp"
#include <string>
#include <memory>

namespace Game {
    enum State {
        MENU,
        GAME,
        END
    };
    class IGameModule {
        public:
            virtual ~IGameModule() = default;
            virtual void setFunctions(
                std::unique_ptr<Display::IWindow> (*)(),
                std::unique_ptr<Display::ITexture> (*)(),
                std::unique_ptr<Display::ISprite> (*)(),
                std::unique_ptr<Display::IRenderer> (*)()
            ) = 0;
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void setState(Game::State state) = 0;
            virtual Game::State getState() const = 0;
            virtual void run() = 0;
            virtual void stop() = 0;
            virtual const std::string &getName() const = 0;
    };
}
