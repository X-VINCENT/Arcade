/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IGameModule
*/

#pragma once
#include "IGameModule.hpp"
#include "Printable.hpp"

#define UP 0
#define DOWN 180
#define LEFT 270
#define RIGHT 90

class IGameObject {
    public:
        virtual ~IGameObject() = default;
        virtual const std::pair<int, int> &getPos() const = 0;
        virtual void setPos(const std::pair<int, int> &pos) = 0;
        virtual int getOrientation() const = 0;
        virtual void setOrientation(int orientation) = 0;
        virtual const Printable &getPrintable() const = 0;
        virtual void setPrintable(const char &c, Printable::Colors color, const std::string &path) = 0;
};
