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
        NCursesWindow(std::string const &title, int framerateLimit,
                      int width, int height);
        ~NCursesWindow() override;
        void create(std::string const &title, int framerateLimit,
                    int width, int height) override;
        void setSize(int width, int height) override;
        void update() override;
        void destroy() override;

    protected:
    private:
        WINDOW *_window;
};
