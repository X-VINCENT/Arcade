/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Window
*/

#pragma once
#include "IWindow.hpp"
#include "IEvent.hpp"
#include <SDL2/SDL.h>

namespace Display {
    class SDL2Window : public IWindow {
    public:
        SDL2Window() = default;
        ~SDL2Window();
        void create(
            std::string const &title,
            int framerateLimit,
            int width,
            int height
        ) override;
        void setRenderer(std::unique_ptr<Display::IRenderer> renderer) override;
        std::unique_ptr<Display::IEvent> getEvent() override;
        std::string &getTitle() override;
        void setTitle(std::string const &title) override;
        bool isOpen() override;
        void clear() override;
        void draw(std::unique_ptr<Display::ISprite> &sprite) override;
        void display() override;
        void close() override;
        SDL_Window *getSDL2Window() const;
    protected:
    private:
        std::string title;
        SDL_Window *window;
        SDL_Renderer *renderer;
    };
};
