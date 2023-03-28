/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Renderer
*/

#pragma once
#include "IRenderer.hpp"
#include "IWindow.hpp"
#include <SDL2/SDL.h>

namespace Display {
    class SDL2Renderer : public IRenderer {
        public:
            SDL2Renderer() = default;
            ~SDL2Renderer() override;
            void create(std::unique_ptr<Display::IWindow> &window) override;
            std::unique_ptr<Display::IRenderer> clone() const override;
            SDL_Renderer *getSDL2Renderer() const;
        protected:
        private:
            SDL_Renderer *renderer;
    };
};
