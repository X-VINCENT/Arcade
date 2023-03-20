/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#pragma once
#include "IWindow.hpp"
#include "IGameModule.hpp"
#include <ncurses.h>
#include <memory>

namespace Display {
    class NCursesWindow : public IWindow {
        public:
            NCursesWindow() = default;
            NCursesWindow(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            );
            ~NCursesWindow() override;
            void create(
                std::string const &title,
                int framerateLimit,
                int width,
                int height
            ) override;
            // IEvent getEvents() override;
            std::string getTitle() override;
            void setTitle(std::string const &title) override;
            bool isOpen() override;
            void clear() override;
            void draw() override;
            void display() override;
            void close() override;

        protected:
        private:
            WINDOW *_window;
            std::string _title;
    };
};
