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
            SDL2Sprite() = default;
            ~SDL2Sprite() override;
            void create(
                std::unique_ptr<ITexture> texture,
                const IIntRect &rect,
                const IVector2f &position
            ) override;
            void create(const SDL2Sprite &);
            Display::IIntRect getRect() override;
            SDL_Rect &getSDLRect();
            void setRect(const Display::IIntRect &rect) override;
            Display::IVector2f getPosition() override;
            void setPosition(const Display::IVector2f &position) override;
            std::unique_ptr<Display::ITexture> getTexture() override;
            void setTexture(std::unique_ptr<Display::ITexture> texture) override;
            void move(const IVector2f &offset) override;
            SDL_Texture &getSDLSprite();

        private:
            SDL_Texture *sprite;
            SDL_Texture *texture;
            SDL_Rect rect;
            SDL_Point position;
    };
}