/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IVector2f
*/

#pragma once
#include <memory>

#include <memory>

namespace Display {
    class IVector2f {
        public:
            virtual ~IVector2f() = default;
            virtual int getX() = 0;
            virtual void setX(int x) = 0;
            virtual int getY() = 0;
            virtual void setY(int y) = 0;
            virtual void set(int x, int y) = 0;
    };
    extern "C" std::unique_ptr<IVector2f> createVector2f();
};
