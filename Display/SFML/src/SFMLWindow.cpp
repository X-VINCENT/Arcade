/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"

Display::SFMLWindow::SFMLWindow(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    this->create(title, framerateLimit, width, height);
}

Display::SFMLWindow::~SFMLWindow()
{
    this->close();
}
#include <iostream>
void Display::SFMLWindow::create(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    this->window.create(sf::VideoMode(width, height), title);
    this->title = title;
}

std::string Display::SFMLWindow::getTitle()
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
    this->window.clear();
}

void Display::SFMLWindow::draw()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    this->window.draw(shape);
}

void Display::SFMLWindow::display()
{
    this->window.display();
}

void Display::SFMLWindow::close()
{
    this->window.close();
}

extern "C" std::unique_ptr<Display::IWindow> createWindow() {
    return std::make_unique<Display::SFMLWindow>();
}
