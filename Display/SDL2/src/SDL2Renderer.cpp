/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Renderer
*/

#include "SDL2Renderer.hpp"
#include "SDL2Window.hpp"
#include <memory>

Display::SDL2Renderer::~SDL2Renderer()
{
    SDL_DestroyRenderer(renderer);
}

void Display::SDL2Renderer::create(std::unique_ptr<Display::IWindow> &window)
{
    Display::SDL2Window sdl2Window = dynamic_cast<Display::SDL2Window &>(*window);
    SDL_Window *sdlWindow = sdl2Window.getSDL2Window();

    this->renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        SDL_Quit();
        exit(84);
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

std::unique_ptr<Display::IRenderer> Display::SDL2Renderer::clone() const
{
    return std::make_unique<Display::SDL2Renderer>(*this);
}

SDL_Renderer *Display::SDL2Renderer::getSDL2Renderer() const
{
    return this->renderer;
}

extern "C" std::unique_ptr<Display::IRenderer> createRenderer()
{
    return std::make_unique<Display::SDL2Renderer>();
}
