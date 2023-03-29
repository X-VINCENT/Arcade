/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"
#include "SFMLEvent.hpp"
#include "SFMLSprite.hpp"
#include <map>

using KeyToEventTypeMap = std::map<sf::Keyboard::Key, Display::KeyType>;
static const KeyToEventTypeMap KeyToEventType = {
    {sf::Keyboard::Key::A, Display::KeyType::A},
    {sf::Keyboard::Key::B, Display::KeyType::B},
    {sf::Keyboard::Key::C, Display::KeyType::C},
    {sf::Keyboard::Key::D, Display::KeyType::D},
    {sf::Keyboard::Key::E, Display::KeyType::E},
    {sf::Keyboard::Key::F, Display::KeyType::F},
    {sf::Keyboard::Key::G, Display::KeyType::G},
    {sf::Keyboard::Key::H, Display::KeyType::H},
    {sf::Keyboard::Key::I, Display::KeyType::I},
    {sf::Keyboard::Key::J, Display::KeyType::J},
    {sf::Keyboard::Key::K, Display::KeyType::K},
    {sf::Keyboard::Key::L, Display::KeyType::L},
    {sf::Keyboard::Key::M, Display::KeyType::M},
    {sf::Keyboard::Key::N, Display::KeyType::N},
    {sf::Keyboard::Key::O, Display::KeyType::O},
    {sf::Keyboard::Key::P, Display::KeyType::P},
    {sf::Keyboard::Key::Q, Display::KeyType::Q},
    {sf::Keyboard::Key::R, Display::KeyType::R},
    {sf::Keyboard::Key::S, Display::KeyType::S},
    {sf::Keyboard::Key::T, Display::KeyType::T},
    {sf::Keyboard::Key::U, Display::KeyType::U},
    {sf::Keyboard::Key::V, Display::KeyType::V},
    {sf::Keyboard::Key::W, Display::KeyType::W},
    {sf::Keyboard::Key::X, Display::KeyType::X},
    {sf::Keyboard::Key::Y, Display::KeyType::Y},
    {sf::Keyboard::Key::Z, Display::KeyType::Z},
    {sf::Keyboard::Key::Num0, Display::KeyType::Num0},
    {sf::Keyboard::Key::Num1, Display::KeyType::Num1},
    {sf::Keyboard::Key::Num2, Display::KeyType::Num2},
    {sf::Keyboard::Key::Num3, Display::KeyType::Num3},
    {sf::Keyboard::Key::Num4, Display::KeyType::Num4},
    {sf::Keyboard::Key::Num5, Display::KeyType::Num5},
    {sf::Keyboard::Key::Num6, Display::KeyType::Num6},
    {sf::Keyboard::Key::Num7, Display::KeyType::Num7},
    {sf::Keyboard::Key::Num8, Display::KeyType::Num8},
    {sf::Keyboard::Key::Num9, Display::KeyType::Num9},
    {sf::Keyboard::Key::Escape, Display::KeyType::Escape},
    {sf::Keyboard::Key::LControl, Display::KeyType::LControl},
    {sf::Keyboard::Key::LShift, Display::KeyType::LShift},
    {sf::Keyboard::Key::LAlt, Display::KeyType::LAlt},
    {sf::Keyboard::Key::LSystem, Display::KeyType::LSystem},
    {sf::Keyboard::Key::RControl, Display::KeyType::RControl},
    {sf::Keyboard::Key::RShift, Display::KeyType::RShift},
    {sf::Keyboard::Key::RAlt, Display::KeyType::RAlt},
    {sf::Keyboard::Key::RSystem, Display::KeyType::RSystem},
    {sf::Keyboard::Key::Menu, Display::KeyType::Menu},
    {sf::Keyboard::Key::LBracket, Display::KeyType::LBracket},
    {sf::Keyboard::Key::RBracket, Display::KeyType::RBracket},
    {sf::Keyboard::Key::Semicolon, Display::KeyType::Semicolon},
    {sf::Keyboard::Key::Comma, Display::KeyType::Comma},
    {sf::Keyboard::Key::Period, Display::KeyType::Period},
    {sf::Keyboard::Key::Quote, Display::KeyType::Quote},
    {sf::Keyboard::Key::Slash, Display::KeyType::Slash},
    {sf::Keyboard::Key::Backslash, Display::KeyType::Backslash},
    {sf::Keyboard::Key::Tilde, Display::KeyType::Tilde},
    {sf::Keyboard::Key::Equal, Display::KeyType::Equal},
    {sf::Keyboard::Key::Hyphen, Display::KeyType::Hyphen},
    {sf::Keyboard::Key::Space, Display::KeyType::Space},
    {sf::Keyboard::Key::Enter, Display::KeyType::Enter},
    {sf::Keyboard::Key::Backspace, Display::KeyType::Backspace},
    {sf::Keyboard::Key::Tab, Display::KeyType::Tab},
    {sf::Keyboard::Key::PageUp, Display::KeyType::PageUp},
    {sf::Keyboard::Key::PageDown, Display::KeyType::PageDown},
    {sf::Keyboard::Key::End, Display::KeyType::End},
    {sf::Keyboard::Key::Home, Display::KeyType::Home},
    {sf::Keyboard::Key::Insert, Display::KeyType::Insert},
    {sf::Keyboard::Key::Delete, Display::KeyType::Delete},
    {sf::Keyboard::Key::Add, Display::KeyType::Add},
    {sf::Keyboard::Key::Subtract, Display::KeyType::Subtract},
    {sf::Keyboard::Key::Multiply, Display::KeyType::Multiply},
    {sf::Keyboard::Key::Divide, Display::KeyType::Divide},
    {sf::Keyboard::Key::Left, Display::KeyType::Left},
    {sf::Keyboard::Key::Right, Display::KeyType::Right},
    {sf::Keyboard::Key::Up, Display::KeyType::Up},
    {sf::Keyboard::Key::Down, Display::KeyType::Down},
    {sf::Keyboard::Key::Numpad0, Display::KeyType::Numpad0},
    {sf::Keyboard::Key::Numpad1, Display::KeyType::Numpad1},
    {sf::Keyboard::Key::Numpad2, Display::KeyType::Numpad2},
    {sf::Keyboard::Key::Numpad3, Display::KeyType::Numpad3},
    {sf::Keyboard::Key::Numpad4, Display::KeyType::Numpad4},
    {sf::Keyboard::Key::Numpad5, Display::KeyType::Numpad5},
    {sf::Keyboard::Key::Numpad6, Display::KeyType::Numpad6},
    {sf::Keyboard::Key::Numpad7, Display::KeyType::Numpad7},
    {sf::Keyboard::Key::Numpad8, Display::KeyType::Numpad8},
    {sf::Keyboard::Key::Numpad9, Display::KeyType::Numpad9},
    {sf::Keyboard::Key::F1, Display::KeyType::F1},
    {sf::Keyboard::Key::F2, Display::KeyType::F2},
    {sf::Keyboard::Key::F3, Display::KeyType::F3},
    {sf::Keyboard::Key::F4, Display::KeyType::F4},
    {sf::Keyboard::Key::F5, Display::KeyType::F5},
    {sf::Keyboard::Key::F6, Display::KeyType::F6},
    {sf::Keyboard::Key::F7, Display::KeyType::F7},
    {sf::Keyboard::Key::F8, Display::KeyType::F8},
    {sf::Keyboard::Key::F9, Display::KeyType::F9},
    {sf::Keyboard::Key::F10, Display::KeyType::F10},
    {sf::Keyboard::Key::F11, Display::KeyType::F11},
    {sf::Keyboard::Key::F12, Display::KeyType::F12},
    {sf::Keyboard::Key::F13, Display::KeyType::F13},
    {sf::Keyboard::Key::F14, Display::KeyType::F14},
    {sf::Keyboard::Key::F15, Display::KeyType::F15},
    {sf::Keyboard::Key::Pause, Display::KeyType::Pause},
    {sf::Keyboard::Key::KeyCount, Display::KeyType::KeyCount},
    {sf::Keyboard::Key::Dash, Display::KeyType::Dash},
    {sf::Keyboard::Key::BackSpace, Display::KeyType::BackSpace},
    {sf::Keyboard::Key::BackSlash, Display::KeyType::BackSlash},
    {sf::Keyboard::Key::SemiColon, Display::KeyType::SemiColon},
    {sf::Keyboard::Key::Return, Display::KeyType::Return}
};

Display::SFMLWindow::~SFMLWindow()
{
    this->close();
}

void Display::SFMLWindow::create(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    this->window.create(sf::VideoMode(width * 10, height * 10), title);
    this->title = title;
}

void Display::SFMLWindow::setRenderer(std::unique_ptr<Display::IRenderer> renderer)
{
    (void)renderer;
}

std::unique_ptr<Display::IEvent> Display::SFMLWindow::getEvent()
{
    sf::Event sfEvent;
    Display::SFMLEvent event;
    Display::KeyType type = Display::KeyType::Unknown;

    this->window.pollEvent(sfEvent);
    type = KeyToEventType.find(sfEvent.key.code)->second;
    if (sfEvent.type == sf::Event::Closed)
        type = Display::KeyType::Return;
    event.setType(type);
    return std::make_unique<Display::SFMLEvent>(event);
}

std::string &Display::SFMLWindow::getTitle()
{
    return this->title;
}

void Display::SFMLWindow::setTitle(std::string const &title)
{
    this->title = title;
}

bool Display::SFMLWindow::isOpen()
{
    return this->window.isOpen();
}

void Display::SFMLWindow::clear()
{
    if (this->isOpen())
        this->window.clear();
}

void Display::SFMLWindow::draw(std::unique_ptr<Display::ISprite> &sprite)
{
    if (!this->isOpen())
        return;

    Display::SFMLSprite &sfmlSprite = dynamic_cast<Display::SFMLSprite &>(*sprite);
    sf::Sprite sfSprite = sfmlSprite.getSfSprite();

    this->window.draw(sfSprite);
}

void Display::SFMLWindow::display()
{
    if (this->isOpen())
        this->window.display();
}

void Display::SFMLWindow::close()
{
    if (this->isOpen())
        this->window.close();
}

extern "C" std::unique_ptr<Display::IWindow> createWindow()
{
    return std::make_unique<Display::SFMLWindow>();
}
