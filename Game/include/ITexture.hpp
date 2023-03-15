/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Printable.hpp
*/

#pragma once
#include "IGameModule.hpp"

namespace Game {
    class ITexture {
    public:
        virtual ~ITexture() = default;
        virtual bool loadFromFile(const std::string &filename) = 0;
    protected:
    private:
    };
}
