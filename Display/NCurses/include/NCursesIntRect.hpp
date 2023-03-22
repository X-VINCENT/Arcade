/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesIntRect
*/

#pragma once
#include "IIntRect.hpp"
#include <ncurses.h>

namespace Display {
    class NCursesIntRect : public IIntRect {
        public:
            NCursesIntRect() = default;
            ~NCursesIntRect();
            void create(int left, int top, int width, int height) override;
            int getLeft() override;
            void setLeft(int left) override;
            int getTop() override;
            void setTop(int top) override;
            int getWidth() override;
            void setWidth(int width) override;
            int getHeight() override;
            void setHeight(int height) override;

        private:
            int left;
            int top;
            int width;
            int height;
    };
}
