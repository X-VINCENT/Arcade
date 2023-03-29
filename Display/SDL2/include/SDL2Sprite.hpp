/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDLSprite
*/

#include "ITexture.hpp"
#include "ISprite.hpp"
#include "SDL2/SDL.h"
#include "SDL2IntRect.hpp"
#include "SDL2Vector2f.hpp"
#include "SDL2Texture.hpp"

namespace Display {
    class SDL2Sprite : public ISprite {
        public:
            SDL2Sprite(
                Display::ITexture &texture,
                const IntRect &rect,
                const Vector2f &position);
            ~SDL2Sprite() override;
            void create(const SDL2Sprite &);
            Display::IntRect getRect() override;
            SDL_Rect &getSDLRect();
            void setRect(const Display::IntRect &rect) override;
            Display::Vector2f getPosition() override;
            void setPosition(const Display::Vector2f &position) override;
            void setTexture(Display::ITexture &texture) override;
            void move(const Vector2f &offset) override;
            SDL_Texture &getSDLSprite();

        private:
            SDL_Texture *sprite;
            SDL_Texture *texture;
            SDL_Rect rect;
            SDL_Point position;
    };
}