/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Text
*/

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "IText.hpp"
#include "Color.hpp"
#include "IFont.hpp"
#include "Vector2f.hpp"

namespace Display {
    class SDL2Text : public IText {
        public:
            SDL2Text(
                const std::string &text,
                const Display::IFont &font,
                const Display::Color &color,
                const Display::Vector2f &position,
                SDL_Renderer *renderer
            );
            ~SDL2Text() override;
            void setText(const std::string &text) override;
            void setFont(const Display::IFont &font) override;
            void setColor(const Display::Color &color) override;
            void setPosition(const Display::Vector2f &position) override;
            Display::Vector2f getPosition() const override;
            void move(const Display::Vector2f &offset) override;
            SDL_Texture &getSDLText();

        private:
            SDL_Renderer *renderer;
            SDL_Surface *surface;
            SDL_Texture *texture;
            TTF_Font *font;
            std::string text;
            SDL_Color color;
            Display::Vector2f position;
    };
};
