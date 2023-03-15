/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"

NCursesWindow::NCursesWindow(std::string const &title, int framerateLimit,
                             int width, int height)
{
    this->create(title, framerateLimit, width, height);
}

NCursesWindow::~NCursesWindow()
{
    this->destroy();
}

void NCursesWindow::create(std::string const &title, int framerateLimit,
                           int width, int height)
{
    this->_window = newwin(height, width, 0, 0);
}

void NCursesWindow::setSize(int width, int height)
{
    wresize(this->_window, height, width);
}

void NCursesWindow::update()
{
    wrefresh(this->_window);
}

void NCursesWindow::destroy()
{
    delwin(this->_window);
}
