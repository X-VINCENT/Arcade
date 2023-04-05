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
            Display::Event getEvent() const override;
            void stop() override;

        private:
            Game::State state;
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::IClock> renderClock;
            std::unique_ptr<Display::IClock> playerClock;
            std::unique_ptr<Display::IClock> centipedeClock;
            std::unique_ptr<Display::IClock> shootClock;
            std::unique_ptr<Display::IClock> scoreClock;
            std::unique_ptr<Display::ISprite> player;
            std::unique_ptr<Display::ITexture> playerTexture;
            std::unique_ptr<Display::ISprite> projectile;
            std::unique_ptr<Display::ITexture> projectileTexture;
            std::vector<std::unique_ptr<Display::ISprite>> centipede;
            std::vector<Direction> centipedeDirections;
            std::unique_ptr<Display::ITexture> centipedeTexture;
            std::unique_ptr<Display::ITexture> obstacleTexture;
            std::vector<std::unique_ptr<Display::ISprite>> obstacles;
            std::vector<int> obstaclesLife;
            std::unique_ptr<Display::IText> scoreText;
            std::unique_ptr<Display::IFont> arialFont;
            std::unique_ptr<Display::IText> gameOverText;
            std::unique_ptr<Display::IText> restartTextLose;
            std::unique_ptr<Display::IText> winText;
            std::unique_ptr<Display::IText> restartTextWin;
            bool canShoot = true;
            int score = 0;
            int centipedeNumber = 1;
            Display::Event event = Display::Event::Unknown;
            void shoot();
            void updateShoot();
            void handleEvents();
            void movePlayer(Direction direction);
            void moveCentipede(Display::IFactory &factory);
            void handleCollision(Display::IFactory &factory);
            void updateWindow();
            void updateWindowWin();
            void updateWindowLose();
    };
}
