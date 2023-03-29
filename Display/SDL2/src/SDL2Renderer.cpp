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

void Display::SDL2Renderer::create(Display::IWindow &window)
{
    SDL_Window *sdlWindow = dynamic_cast<Display::SDL2Window &>(window).getSDL2Window();
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
