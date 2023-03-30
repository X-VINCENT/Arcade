/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IGameModule
*/

#pragma once
#include "IFactory.hpp"
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
            virtual void update(Display::IFactory &factory) = 0;
            virtual void setState(Game::State state) = 0;
            virtual Game::State getState() const = 0;
            virtual void run(Display::IFactory &factory) = 0;
            virtual void stop() = 0;
            virtual const std::string &getName() const = 0;
    };
}
