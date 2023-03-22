/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesVector2f
*/

#pragma once
#include "IVector2f.hpp"

namespace Display {
    class NCursesVector2f : public IVector2f {
        public:
            NCursesVector2f() = default;
            ~NCursesVector2f();
            void create(float x, float y) override;
            float getX() override;
            void setX(float x) override;
            float getY() override;
            void setY(float y) override;

        private:
            float x;
            float y;
    };
}
