/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#pragma once
#include "IWindow.hpp"
#include <ncurses.h>

class NCursesWindow : public IWindow {
    public:
        NCursesWindow();
        ~NCursesWindow() override;
        void create(int width, int height, int posX, int posY);
        void setSize(int width, int height);
        void update() override;
        void destroy() override;

    protected:
    private:
        WINDOW _window;
};
