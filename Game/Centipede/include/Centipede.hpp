/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Centipede.hpp
*/

#pragma once
#include "IGameModule.hpp"
#include "IFactory.hpp"
#include "ISprite.hpp"
#include "IWindow.hpp"
#include "IntRect.hpp"
#include "Vector2f.hpp"
#include <memory>
#include <string>
#include <vector>

namespace Game {
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class Centipede : public IGameModule {
        public:
            Centipede(Display::IFactory &factory);
            ~Centipede() override;
            void update(Display::IFactory &factory) override;
            void setState(Game::State state) override;
            Game::State getState() const override;
            void run(Display::IFactory &factory) override;
            void stop() override;
            const std::string &getName() const override;

        private:
            std::string name;
            Game::State state;
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::ISprite> player;
            std::unique_ptr<Display::ITexture> playerTexture;
            std::vector<std::unique_ptr<Display::ISprite>> centipede;
            std::unique_ptr<Display::ITexture> centipedeTexture;
            void handleEvents();
            void movePlayer(Direction direction);
            void moveCentipede();
            void handleCollision();
            void updateWindow();
    };
}
