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

void init_colors()
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void Display::NCursesWindow::create(std::string const &title, int framerateLimit,
                           int width, int height)
{
    initscr();
    start_color();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_colors();
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
    clear();
    wclear(this->_window);
}

void Display::NCursesWindow::draw()
{
    refresh();
    wrefresh(this->_window);
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::NCursesWindow>();
}
