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
    class Snake : public IGameModule {
        public:
            Snake();
            ~Snake() override;
            void setFunctions(
                std::unique_ptr<Display::IWindow> (*window)(),
                std::unique_ptr<Display::ISprite> (*sprite)(),
                std::unique_ptr<Display::ITexture> (*texture)()
            ) override;
            void init() override;
            void update() override;
            void stop() override;
            const std::string &getName() const override;

        private:
            std::string name;
            std::unique_ptr<Display::IWindow> windowPtr;
            std::unique_ptr<Display::ISprite> spritePtr;
            std::unique_ptr<Display::ITexture> texturePtr;
            std::unique_ptr<Display::ITexture> snakeTexture;
            std::unique_ptr<Display::ITexture> foodTexture;
            std::vector<std::unique_ptr<Display::ISprite>> snake;
            std::unique_ptr<Display::ISprite> food;
    };
    extern "C" std::unique_ptr<Game::IGameModule> createGame();
}
