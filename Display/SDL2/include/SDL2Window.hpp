/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Window
*/

#pragma once
#include "IWindow.hpp"
#include <SDL2/SDL.h>

namespace Display {
    class SDL2Window : public IWindow {
        public:
            SDL2Window() = default;
            SDL2Window(
                const std::string &title,
                int framerateLimit,
                int width,
                int height);
            ~SDL2Window();
            SDL2Window(const Display::SDL2Window &other) = delete;
            SDL2Window(Display::SDL2Window &&other) = delete;
            Display::SDL2Window &operator=(const Display::SDL2Window &other) = delete;
            Display::SDL2Window &operator=(Display::SDL2Window &&other) = delete;
            Display::Event getEvent() override;
            void setTitle(const std::string &title) override;
            bool isOpen() override;
            void clear() override;
            void draw(Display::ISprite &sprite) override;
            void display() override;
            void close() override;
            SDL_Window *getWindow() const;
            SDL_Renderer *getRenderer() const;

        private:
            SDL_Window *window;
            SDL_Renderer *renderer;
    };
};
