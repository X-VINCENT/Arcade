/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Font
*/

#pragma once
#include "IFont.hpp"
#include <SDL2/SDL_ttf.h>

namespace Display {
    class SDL2Font : public IFont {
        public:
            SDL2Font(const std::string &fontPath);
            ~SDL2Font() override;
            void setFont(const std::string &fontPath) override;
            TTF_Font *getSDLFont() const;
            int getFontSize() const;

        private:
            TTF_Font *font;
    };
};
