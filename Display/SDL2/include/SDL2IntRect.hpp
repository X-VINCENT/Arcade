/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLIntRect
*/

#pragma once
#include "IntRect.hpp"
#include "SDL2/SDL_rect.h"

namespace Display {
    SDL_Rect toSdlIntRect(const IntRect &);
    IntRect toIIntRect(const SDL_Rect &);
}