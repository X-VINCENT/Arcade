/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"
#include <memory>
#include <string>

namespace Game {
    class Snake : public IGameModule {
        public:
            Snake();
            ~Snake();
            void init() override;
            void stop() override;
            const std::string &getName() const override;

        private:
            std::string name;
    };
    extern "C" std::unique_ptr<Game::IGameModule> createGame();
}
