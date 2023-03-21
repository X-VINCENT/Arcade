/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"

Display::SFMLWindow::SFMLWindow(std::string const &title, int
framerateLimit,
        int width, int height)
{
}

Display::SFMLWindow::~SFMLWindow()
{
}

void Display::SFMLWindow::create(std::string const &title, int framerateLimit,
        int width, int height)
{
    this->_window = newwin(height, width, 0, 0);
}

void Display::SFMLWindow::setSize(int width, int height)
{
    wresize(this->_window, height, width);
}

void Display::SFMLWindow::destroy()
{
    delwin(this->_window);
}

void Display::SFMLWindow::setFramerateLimit(int framerateLimit)
{
}

void Display::SFMLWindow::getFramerateLimit()
{
}

void Display::SFMLWindow::getSize()
{
}

void Display::SFMLWindow::getPosition()
{
}

void Display::SFMLWindow::setPosition(int x, int y)
{
}

void Display::SFMLWindow::clear()
{
}

void Display::SFMLWindow::draw()
{
    wrefresh(this->_window);
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::SFMLWindow
    >();
}
