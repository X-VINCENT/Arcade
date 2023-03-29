/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesWindow
*/

#include "NCursesWindow.hpp"
#include "NCursesEvent.hpp"
#include "NCursesTexture.hpp"
#include <map>

using KeyToEventTypeMap = std::map<int, Display::KeyType>;
static const KeyToEventTypeMap KeyToEventType = {
    {97, Display::KeyType::A},
    {98, Display::KeyType::B},
    {99, Display::KeyType::C},
    {100, Display::KeyType::D},
    {101, Display::KeyType::E},
    {102, Display::KeyType::F},
    {103, Display::KeyType::G},
    {104, Display::KeyType::H},
    {105, Display::KeyType::I},
    {106, Display::KeyType::J},
    {107, Display::KeyType::K},
    {108, Display::KeyType::L},
    {109, Display::KeyType::M},
    {110, Display::KeyType::N},
    {111, Display::KeyType::O},
    {112, Display::KeyType::P},
    {113, Display::KeyType::Q},
    {114, Display::KeyType::R},
    {115, Display::KeyType::S},
    {116, Display::KeyType::T},
    {117, Display::KeyType::U},
    {118, Display::KeyType::V},
    {119, Display::KeyType::W},
    {120, Display::KeyType::X},
    {121, Display::KeyType::Y},
    {122, Display::KeyType::Z},
    {48, Display::KeyType::Num0},
    {49, Display::KeyType::Num1},
    {50, Display::KeyType::Num2},
    {51, Display::KeyType::Num3},
    {52, Display::KeyType::Num4},
    {53, Display::KeyType::Num5},
    {54, Display::KeyType::Num6},
    {55, Display::KeyType::Num7},
    {56, Display::KeyType::Num8},
    {57, Display::KeyType::Num9},
    {27, Display::KeyType::Escape},
    {32, Display::KeyType::Space},
    {10, Display::KeyType::Enter},
    {KEY_BACKSPACE, Display::KeyType::Backspace},
    {9, Display::KeyType::Tab},
    {KEY_PPAGE, Display::KeyType::PageUp},
    {KEY_NPAGE, Display::KeyType::PageDown},
    {KEY_END, Display::KeyType::End},
    {KEY_HOME, Display::KeyType::Home},
    {KEY_IC, Display::KeyType::Insert},
    {KEY_DC, Display::KeyType::Delete},
    {KEY_LEFT, Display::KeyType::Left},
    {KEY_RIGHT, Display::KeyType::Right},
    {KEY_UP, Display::KeyType::Up},
    {KEY_DOWN, Display::KeyType::Down},
    {KEY_F(1), Display::KeyType::F1},
    {KEY_F(2), Display::KeyType::F2},
    {KEY_F(3), Display::KeyType::F3},
    {KEY_F(4), Display::KeyType::F4},
    {KEY_F(5), Display::KeyType::F5},
    {KEY_F(6), Display::KeyType::F6},
    {KEY_F(7), Display::KeyType::F7},
    {KEY_F(8), Display::KeyType::F8},
    {KEY_F(9), Display::KeyType::F9},
    {KEY_F(10), Display::KeyType::F10},
    {KEY_F(11), Display::KeyType::F11},
    {KEY_F(12), Display::KeyType::F12},
    {KEY_F(13), Display::KeyType::F13},
    {KEY_F(14), Display::KeyType::F14},
    {KEY_F(15), Display::KeyType::F15},
    {KEY_SUSPEND, Display::KeyType::Pause},
    {45, Display::KeyType::Dash},
    {8, Display::KeyType::BackSpace},
    {92, Display::KeyType::BackSlash},
    {59, Display::KeyType::SemiColon},
    {13, Display::KeyType::Return}
};

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

void Display::NCursesWindow::setRenderer(std::unique_ptr<Display::IRenderer> renderer)
{
    (void)renderer;
}

std::unique_ptr<Display::IEvent> Display::NCursesWindow::getEvent()
{
    int key = getch();
    Display::NCursesEvent event;
    Display::KeyType type = Display::KeyType::Unknown;

    if (key != ERR)
        type = KeyToEventType.find(key)->second;
    event.setType(type);
    return std::make_unique<Display::NCursesEvent>(event);
}

std::string &Display::NCursesWindow::getTitle()
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
    if (this->isOpen())
        wclear(this->window);
}

void Display::NCursesWindow::draw(std::unique_ptr<Display::ISprite> &sprite)
{
    if (!this->isOpen())
        return;

    Display::NCursesTexture ncursesTexture =
        dynamic_cast<Display::NCursesTexture &>(*sprite->getTexture());
    char c = ncursesTexture.getNCursesTexture();

    mvwprintw(this->window, sprite->getPosition().y, sprite->getPosition().x, &c);
}

void Display::NCursesWindow::display()
{
    if (this->isOpen())
        wrefresh(this->window);
}

void Display::NCursesWindow::close()
{
    if (this->isOpen())
        delwin(this->window);
}

extern "C" std::unique_ptr<Display::IWindow> createWindow()
{
    return std::make_unique<Display::NCursesWindow>();
}
