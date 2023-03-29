/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLIntRect
*/

#include "SDL2IntRect.hpp"

namespace Display
{
    SDL_Rect toSdlIntRect(const IntRect &IIntrect)
    {
        SDL_Rect dest{};

        dest.x = IIntrect.left;
        dest.y = IIntrect.top;
        dest.w = IIntrect.width;
        dest.h = IIntrect.height;
        return dest;
    }

    IntRect toIIntRect(const SDL_Rect &sdlIntRect)
    {
        IntRect dest{};

        dest.top = sdlIntRect.y;
        dest.left = sdlIntRect.x;
        dest.height = sdlIntRect.h;
        dest.width = sdlIntRect.w;
        return dest;
    }
}
