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
    SDL_Window *sdlWindow = dynamic_cast<SDL2Window *>(window.get())->getSDL2Window();
    if (sdlWindow == nullptr) {
        SDL_Log("Unable to get SDL2window: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    this->renderer = renderer;
}

std::unique_ptr<Display::IRenderer> Display::SDL2Renderer::clone() const
{
    return std::make_unique<Display::SDL2Renderer>(*this);
}

SDL_Renderer *Display::SDL2Renderer::getSDL2Renderer() const
{
    if (this->renderer == nullptr) {
        SDL_Log("Unable to get SDL2renderer: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
    return this->renderer;
}

extern "C" std::unique_ptr<Display::IRenderer> createRenderer()
{
    return std::make_unique<Display::SDL2Renderer>();
}
