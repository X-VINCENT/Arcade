/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesText
*/

#include "NCursesText.hpp"

Display::NCursesText::NCursesText(
    const std::string &text,
    const Display::Color &color,
    const Display::Vector2f &position
)
{
    this->text = text;
    this->color = color;
    this->position = position;
}

Display::NCursesText::~NCursesText()
{
}

void Display::NCursesText::setText(const std::string &src)
{
    this->text = src;
}

void Display::NCursesText::setFont(const Display::IFont &src)
{
    (void)src;
}

void Display::NCursesText::setColor(const Display::Color &src)
{
    this->color = src;
}

void Display::NCursesText::setPosition(const Display::Vector2f &src)
{
    this->position = src;
}

Display::Vector2f Display::NCursesText::getPosition() const
{
    return this->position;
}

void Display::NCursesText::move(const Display::Vector2f &offset)
{
    this->position.x += offset.x;
    this->position.y += offset.y;
}

std::string &Display::NCursesText::getText()
{
    return this->text;
}

Display::Color Display::NCursesText::getColor() const
{
    return this->color;
}
