/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#pragma once
#include "SDL2Vector2f.hpp"


SDL_Point Display::toSdlVector2f(const IVector2f &src)
{
    SDL_Point dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;

}

Display::IVector2f Display::toIVector2f(const SDL_Point &src)
{
    Display::IVector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;
}