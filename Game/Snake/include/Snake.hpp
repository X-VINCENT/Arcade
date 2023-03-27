/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"
#include "ISprite.hpp"
#include "IEvent.hpp"
#include "IWindow.hpp"
#include "IIntRect.hpp"
#include "IVector2f.hpp"
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
    class Snake : public IGameModule {
        public:
            Snake();
            ~Snake() override;
            void setFunctions(
                std::unique_ptr<Display::IWindow> (*window)(),
                std::unique_ptr<Display::ITexture> (*texture)(),
                std::unique_ptr<Display::ISprite> (*sprite)()
            ) override;
            void init() override;
            void update() override;
            void setState(Game::State state) override;
            Game::State getState() const override;
            void run() override;
            void stop() override;
            const std::string &getName() const override;

        private:
            std::string name;
            Game::State state;
            std::unique_ptr<Display::IWindow> (*createWindow)();
            std::unique_ptr<Display::ITexture> (*createTexture)();
            std::unique_ptr<Display::ISprite> (*createSprite)();
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::ITexture> snakeTexture;
            std::unique_ptr<Display::ITexture> foodTexture;
            std::vector<std::unique_ptr<Display::ISprite>> snake;
            std::unique_ptr<Display::ISprite> food;
            Direction direction = Direction::RIGHT;
            void handleEvents();
            void moveSnake();
            void handleEat();
            void handleCollision();
            void updateWindow();
    };
    extern "C" std::unique_ptr<Game::IGameModule> createGame();
}
