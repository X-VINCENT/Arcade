/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLIntRect
*/

#pragma once
#include "IIntRect.hpp"
#include "SDL2/SDL_rect.h"

namespace Display {
    SDL_Rect toSdlIntRect(const IIntRect &);
    IIntRect toIIntRect(const SDL_Rect &);
}