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
            Snake(Display::IFactory &factory, std::string username);
            ~Snake() override;
            void update(Display::IFactory &factory) override;
            void setState(Game::State state) override;
            Game::State getState() const override;
            Display::Event getEvent() const override;
            void stop() override;

        private:
            Game::State state;
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::ITexture> mapTexture;
            std::unique_ptr<Display::ITexture> bodyTexture;
            std::unique_ptr<Display::ITexture> headTexture;
            std::unique_ptr<Display::ITexture> foodTexture;
            std::unique_ptr<Display::IFont> arialFont;
            std::unique_ptr<Display::IClock> renderClock;
            std::unique_ptr<Display::IClock> snakeClock;
            std::unique_ptr<Display::IClock> speedMultiplicatorClock;
            std::unique_ptr<Display::ISprite> map;
            std::vector<std::unique_ptr<Display::ISprite>> snake;
            std::unique_ptr<Display::ISprite> food;
            std::unique_ptr<Display::IText> scoreText;
            std::unique_ptr<Display::IText> gameOverText;
            std::unique_ptr<Display::IText> restartTextLose;
            std::unique_ptr<Display::IText> winText;
            std::unique_ptr<Display::IText> restartTextWin;
            Direction direction = Direction::RIGHT;
            int score;
            float snakeSpeed;
            int isBoosting;
            Display::Event event = Display::Event::Unknown;
            std::string username;
            void handleEvents();
            void moveSnake();
            void handleEat(Display::IFactory &factory);
            void handleCollision();
            void updateSpeed();
            void updateWindow();
            void updateWindowWin();
            void updateWindowLose();
            void saveScore();
    };
}
