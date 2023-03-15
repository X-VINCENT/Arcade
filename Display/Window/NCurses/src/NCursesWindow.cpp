/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "../include/NCursesWindow.hpp"

NCursesWindow::NCursesWindow() : _window(nullptr)
{
}

NCursesWindow::~NCursesWindow()
{
    this->destroy();
}

void NCursesWindow::create(int width, int height, int posX, int posY) {
    this->_window = newwin(height, width, posX, posY);
}

void NCursesWindow::setSize(int width, int height) {
    wresize(this->_window, height, width);
}

void NCursesWindow::update() {
    wrefresh(this->_window);
}

void NCursesWindow::destroy() {
    delwin(this->_window);
}
