/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"
#include "NCursesTexture.hpp"
#include "NCursesSprite.hpp"
#include "NCursesText.hpp"

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

Display::NCursesWindow::NCursesWindow(
    const std::string &title,
    int framerateLimit,
    int width,
    int height
)
{
    initscr();
    raw();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_colors();
    this->window = newwin(height, width, 0, 0);
    wattron(this->window, COLOR_PAIR(7));
}

Display::NCursesWindow::~NCursesWindow()
{
    this->close();
}

Display::Event Display::NCursesWindow::getEvent()
{
    int key = getch();

    switch (key) {
        case 97:
            return Display::Event::A;
        case 98:
            return Display::Event::B;
        case 99:
            return Display::Event::C;
        case 100:
            return Display::Event::D;
        case 101:
            return Display::Event::E;
        case 102:
            return Display::Event::F;
        case 103:
            return Display::Event::G;
        case 104:
            return Display::Event::H;
        case 105:
            return Display::Event::I;
        case 106:
            return Display::Event::J;
        case 107:
            return Display::Event::K;
        case 108:
            return Display::Event::L;
        case 109:
            return Display::Event::M;
        case 110:
            return Display::Event::N;
        case 111:
            return Display::Event::O;
        case 112:
            return Display::Event::P;
        case 113:
            return Display::Event::Q;
        case 114:
            return Display::Event::R;
        case 115:
            return Display::Event::S;
        case 116:
            return Display::Event::T;
        case 117:
            return Display::Event::U;
        case 118:
            return Display::Event::V;
        case 119:
            return Display::Event::W;
        case 120:
            return Display::Event::X;
        case 121:
            return Display::Event::Y;
        case 122:
            return Display::Event::Z;
        case 48:
            return Display::Event::Num0;
        case 49:
            return Display::Event::Num1;
        case 50:
            return Display::Event::Num2;
        case 51:
            return Display::Event::Num3;
        case 52:
            return Display::Event::Num4;
        case 53:
            return Display::Event::Num5;
        case 54:
            return Display::Event::Num6;
        case 55:
            return Display::Event::Num7;
        case 56:
            return Display::Event::Num8;
        case 57:
            return Display::Event::Num9;
        case KEY_LEFT:
            return Display::Event::Left;
        case KEY_RIGHT:
            return Display::Event::Right;
        case KEY_UP:
            return Display::Event::Up;
        case KEY_DOWN:
            return Display::Event::Down;
        case 27:
            return Display::Event::Escape;
        case 13:
            return Display::Event::Enter;
        case 32:
            return Display::Event::Space;
        default:
            break;
    }
    return Display::Event::Unknown;
}

void Display::NCursesWindow::setTitle(const std::string &title)
{
    (void)title;
}

bool Display::NCursesWindow::isOpen()
{
    return this->window != nullptr;
}

void Display::NCursesWindow::clear()
{
    if (!this->window)
        return;
    wclear(this->window);
}

void Display::NCursesWindow::draw(Display::ISprite &sprite)
{
    if (!this->window)
        return;

    Display::NCursesSprite &ncursesSprite = dynamic_cast<Display::NCursesSprite &>(sprite);
    char c = ncursesSprite.getChar();
    Vector2f pos = sprite.getPosition();

    mvwprintw(this->window, pos.y, pos.x, "%c", c);
}

void Display::NCursesWindow::draw(Display::IText &text)
{
    if (!this->window)
        return;

    Display::NCursesText &ncursesText = dynamic_cast<Display::NCursesText &>(text);
    std::string str = ncursesText.getText();
    Vector2f pos = text.getPosition();

    mvwprintw(this->window, pos.y, pos.x, "%s", str.c_str());
}

void Display::NCursesWindow::display()
{
    if (!this->window)
        return;
    wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    if (!this->window)
        return;
    delwin(this->window);
}
