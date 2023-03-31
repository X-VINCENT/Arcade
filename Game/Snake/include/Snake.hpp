/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
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
    class Snake : public IGameModule {
        public:
            Snake(Display::IFactory &factory);
            ~Snake() override;
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
            std::unique_ptr<Display::ITexture> snakeTexture;
            std::unique_ptr<Display::ITexture> foodTexture;
            std::unique_ptr<Display::IFont> arialFont;
            std::vector<std::unique_ptr<Display::ISprite>> snake;
            std::unique_ptr<Display::ISprite> food;
            std::unique_ptr<Display::IText> scoreText;
            Direction direction = Direction::RIGHT;
            int score;
            void handleEvents();
            void moveSnake();
            void handleEat(Display::IFactory &factory);
            void handleCollision();
            void updateWindow();
    };
}
