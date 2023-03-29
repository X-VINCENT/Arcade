/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"
#include "SFMLSprite.hpp"

Display::SFMLWindow::SFMLWindow(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    this->window.create(sf::VideoMode(width * 10, height * 10), title);
    this->window.setFramerateLimit(framerateLimit);
}

Display::SFMLWindow::~SFMLWindow()
{
    this->close();
}

Display::Event Display::SFMLWindow::getEvent()
{
    sf::Event event;
    bool isKeyPressed = false;

    this->window.pollEvent(event);
    switch (event.key.code) {
        case sf::Keyboard::Key::A:
            return Display::Event::A;
        case sf::Keyboard::Key::B:
            return Display::Event::B;
        case sf::Keyboard::Key::C:
            return Display::Event::C;
        case sf::Keyboard::Key::D:
            return Display::Event::D;
        case sf::Keyboard::Key::E:
            return Display::Event::E;
        case sf::Keyboard::Key::F:
            return Display::Event::F;
        case sf::Keyboard::Key::G:
            return Display::Event::G;
        case sf::Keyboard::Key::H:
            return Display::Event::H;
        case sf::Keyboard::Key::I:
            return Display::Event::I;
        case sf::Keyboard::Key::J:
            return Display::Event::J;
        case sf::Keyboard::Key::K:
            return Display::Event::K;
        case sf::Keyboard::Key::L:
            return Display::Event::L;
        case sf::Keyboard::Key::M:
            return Display::Event::M;
        case sf::Keyboard::Key::N:
            return Display::Event::N;
        case sf::Keyboard::Key::O:
            return Display::Event::O;
        case sf::Keyboard::Key::P:
            return Display::Event::P;
        case sf::Keyboard::Key::Q:
            return Display::Event::Q;
        case sf::Keyboard::Key::R:
            return Display::Event::R;
        case sf::Keyboard::Key::S:
            return Display::Event::S;
        case sf::Keyboard::Key::T:
            return Display::Event::T;
        case sf::Keyboard::Key::U:
            return Display::Event::U;
        case sf::Keyboard::Key::V:
            return Display::Event::V;
        case sf::Keyboard::Key::W:
            return Display::Event::W;
        case sf::Keyboard::Key::X:
            return Display::Event::X;
        case sf::Keyboard::Key::Y:
            return Display::Event::Y;
        case sf::Keyboard::Key::Z:
            return Display::Event::Z;
        case sf::Keyboard::Key::Num0:
            return Display::Event::Num0;
        case sf::Keyboard::Key::Num1:
            return Display::Event::Num1;
        case sf::Keyboard::Key::Num2:
            return Display::Event::Num2;
        case sf::Keyboard::Key::Num3:
            return Display::Event::Num3;
        case sf::Keyboard::Key::Num4:
            return Display::Event::Num4;
        case sf::Keyboard::Key::Num5:
            return Display::Event::Num5;
        case sf::Keyboard::Key::Num6:
            return Display::Event::Num6;
        case sf::Keyboard::Key::Num7:
            return Display::Event::Num7;
        case sf::Keyboard::Key::Num8:
            return Display::Event::Num8;
        case sf::Keyboard::Key::Num9:
            return Display::Event::Num9;
        case sf::Keyboard::Key::Left:
            return Display::Event::Left;
        case sf::Keyboard::Key::Right:
            return Display::Event::Right;
        case sf::Keyboard::Key::Up:
            return Display::Event::Up;
        case sf::Keyboard::Key::Down:
            return Display::Event::Down;
        case sf::Keyboard::Key::Escape:
            return Display::Event::Escape;
        case sf::Keyboard::Key::Enter:
            return Display::Event::Enter;
        case sf::Keyboard::Key::Space:
            return Display::Event::Space;
        default:
            break;
    }

    switch (event.type) {
        case sf::Event::Closed:
            return Display::Event::Close;
        default:
            break;
    }

    return Display::Event::Unknown;
}

void Display::SFMLWindow::setTitle(std::string const &title)
{
    this->window.setTitle(title);
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

void Display::SFMLWindow::draw(Display::ISprite &sprite)
{
    if (!this->isOpen())
        return;

    Display::SFMLSprite &sfmlSprite = dynamic_cast<Display::SFMLSprite &>(sprite);
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
