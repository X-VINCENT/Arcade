/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#pragma once
#include "IWindow.hpp"
#include <ncurses.h>

namespace Display {
    class NCursesWindow : public IWindow {
        public:
            NCursesWindow() = default;
            NCursesWindow(
                const std::string &title,
                int framerateLimit,
                int width,
                int height
            );
            ~NCursesWindow();
            NCursesWindow(const Display::NCursesWindow &other) = delete;
            NCursesWindow(Display::NCursesWindow &&other) = delete;
            Display::NCursesWindow &operator=(const Display::NCursesWindow &other) = delete;
            Display::NCursesWindow &operator=(Display::NCursesWindow &&other) = delete;
            Display::Event getEvent() override;
            void setTitle(const std::string &title) override;
            bool isOpen() override;
            void clear() override;
            void draw(Display::ISprite &sprite) override;
            void draw(Display::IText &text) override;
            void display() override;
            void close() override;

        private:
            WINDOW *window;
    };
};
