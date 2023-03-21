/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"

Display::NCursesWindow::NCursesWindow(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    this->create(title, framerateLimit, width, height);
}

Display::NCursesWindow::~NCursesWindow()
{
    this->close();
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

void Display::NCursesWindow::create(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    initscr();
    start_color();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_colors();
    this->window = newwin(height, width, 0, 0);
    this->title = title;
    wattron(this->window, COLOR_PAIR(7));
}

/* IEvent Display::NCursesWindow::getEvents()
{
} */

std::string Display::NCursesWindow::getTitle()
{
    return this->title;
}

void Display::NCursesWindow::setTitle(std::string const &title)
{
    this->title = title;
    if (this->window != nullptr)
        wattron(this->window, COLOR_PAIR(7));
}

bool Display::NCursesWindow::isOpen()
{
    return this->window != nullptr;
}

void Display::NCursesWindow::clear()
{
    wclear(this->window);
}

void Display::NCursesWindow::draw()
{
}

void Display::NCursesWindow::display()
{
    wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    delwin(this->window);
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::NCursesWindow>();
}
