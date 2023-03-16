/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"
#include "IWindow.hpp"

Display::NCursesWindow::NCursesWindow(std::string const &title, int
framerateLimit,
                             int width, int height)
{
}

Display::NCursesWindow::~NCursesWindow()
{
}

void Display::NCursesWindow::create(std::string const &title, int framerateLimit,
                           int width, int height)
{
    this->_window = newwin(height, width, 0, 0);
}

void Display::NCursesWindow::setSize(int width, int height)
{
    wresize(this->_window, height, width);
}

void Display::NCursesWindow::destroy()
{
    delwin(this->_window);
}

void Display::NCursesWindow::setFramerateLimit(int framerateLimit)
{
}

void Display::NCursesWindow::getFramerateLimit()
{
}

void Display::NCursesWindow::getSize()
{
}

void Display::NCursesWindow::getPosition()
{
}

void Display::NCursesWindow::setPosition(int x, int y)
{
}

void Display::NCursesWindow::clear()
{
}

void Display::NCursesWindow::draw()
{
    wrefresh(this->_window);
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::NCursesWindow>();
}
