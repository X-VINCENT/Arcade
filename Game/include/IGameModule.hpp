/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IGameModule
*/

#pragma once
#include "IFactory.hpp"

namespace Game {
    enum State {
        MENU,
        GAME,
        WIN,
        LOSE
    };
    class IGameModule {
        public:
            virtual ~IGameModule() = default;
            virtual void update(Display::IFactory &factory) = 0;
            virtual void setState(Game::State state) = 0;
            virtual Game::State getState() const = 0;
            virtual Display::Event getEvent() const = 0;
            virtual void stop() = 0;
    };
}
