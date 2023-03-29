/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLVector2f
*/

#include "SDL2Vector2f.hpp"

SDL_Point Display::toSdlVector2f(const Vector2f &src)
{
    SDL_Point dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;

}

Display::Vector2f Display::toIVector2f(const SDL_Point &src)
{
    Display::Vector2f dest;

    dest.x = src.x;
    dest.y = src.y;
    return dest;
}
