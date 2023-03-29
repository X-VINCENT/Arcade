/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLVector2f
*/

#pragma once
#include "Vector2f.hpp"
#include "SDL2/SDL_rect.h"

namespace Display {
    SDL_Point toSdlVector2f(const Vector2f &src);
    Vector2f toIVector2f(const SDL_Point &src);
}