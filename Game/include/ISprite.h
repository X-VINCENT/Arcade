/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ISprite
*/

#include "ITexture.hpp"

#ifndef ARCADE_ISPRITE_H
#define ARCADE_ISPRITE_H

namespace Game {

    class ISprite {
    public:
        virtual ~ISprite() = default;
        virtual ISprite &get() noexcept = 0;
        virtual void setColor() = 0;
        virtual const IColor &getColor();
        virtual ITexture &getTexture() noexcept = 0;
        virtual void setTexture(Game::ITexture) = 0;
    protected:
    private:
    };
}

#endif //ARCADE_ISPRITE_H
