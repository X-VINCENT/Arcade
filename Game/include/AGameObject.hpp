/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** AGameObject
*/

#pragma once
#include "IGameObject.hpp"

namespace Game {

    class AGameObject : public IGameObject {
    public:
        AGameObject(std::pair<int, int> pos, int orientation, char c,
                Game::IColor color, std::string path);

        ~AGameObject() override = default;

        virtual const std::pair<int, int> &getPos() const;

        void setPos(const std::pair<int, int> &pos) override;

        virtual int getOrientation() const;

        void setOrientation(int orientation) override;

        virtual const Printable &getPrintable() const;

        void setPrintable(const char &c, IColor color,
                const std::string &path) override;

    protected:
    private:
        std::pair<int, int> pos;
        int orientation;
    };
}
