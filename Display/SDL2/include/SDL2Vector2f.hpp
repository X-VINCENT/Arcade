/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLVector2f
*/

#pragma once
#include "IVector2f.hpp"
#include "SDL2/SDL_rect.h"

namespace Display {
    SDL_Point toSdlVector2f(const IVector2f &src);
    IVector2f toIVector2f(const SDL_Point &src);
}