/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Text
*/

#include "SDL2Exception.hpp"
#include "SDL2Text.hpp"
#include "SDL2Font.hpp"

SDL_Color colorToSDLColor(const Display::Color &color)
{
    switch (color) {
        case Display::Color::BLACK:
            return {0, 0, 0};
        case Display::Color::WHITE:
            return {255, 255, 255};
        case Display::Color::RED:
            return {255, 0, 0};
        case Display::Color::GREEN:
            return {0, 255, 0};
        case Display::Color::BLUE:
            return {0, 0, 255};
        case Display::Color::YELLOW:
            return {255, 255, 0};
        case Display::Color::MAGENTA:
            return {255, 0, 255};
        case Display::Color::CYAN:
            return {0, 255, 255};
        default:
            return {255, 255, 255};
    }
}

Display::SDL2Text::SDL2Text(
    const std::string &text,
    const Display::IFont &font,
    const Display::Color &color,
    const Display::Vector2f &position,
    SDL_Renderer *renderer
)
{
    if (!renderer) {
        SDL_Log("Invalid renderer: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

    Display::SDL2Font sdlFont = dynamic_cast<const Display::SDL2Font &>(font);

    this->font = sdlFont.getSDLFont();
    if (!this->font) {
        SDL_Log("Invalid font: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
    this->fontSize = sdlFont.getFontSize();

    this->color = colorToSDLColor(color);

    this->surface = TTF_RenderText_Solid(this->font, text.c_str(), this->color);
    if (!this->surface) {
        SDL_Log("Unable to create text: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }

    this->renderer = renderer;
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (!this->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

    this->text = text;
    this->position = position;
}

Display::SDL2Text::~SDL2Text()
{
    SDL_DestroyTexture(this->texture);
    SDL_FreeSurface(this->surface);
}
#include <iostream>
void Display::SDL2Text::setText(const std::string &src)
{
    if (!this->font) {
        SDL_Log("Invalid font");
        SDL_Quit();
        exit(84);
    }

    if (!this->renderer) {
        SDL_Log("Invalid renderer");
        SDL_Quit();
        exit(84);
    }

    this->text = src;
    if (this->surface)
        SDL_FreeSurface(this->surface);
    this->surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
    if (!this->surface) {
        SDL_Log("Unable to create text: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }

    if (this->texture)
        SDL_DestroyTexture(this->texture);
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (!this->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
}

void Display::SDL2Text::setFont(const Display::IFont &src)
{
    Display::SDL2Font sdlFont = dynamic_cast<const Display::SDL2Font &>(src);

    this->font = sdlFont.getSDLFont();
    if (this->surface)
        SDL_FreeSurface(this->surface);
    this->surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
    if (!this->surface) {
        SDL_Log("Unable to create text: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }

    if (this->texture)
        SDL_DestroyTexture(this->texture);
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (!this->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }

}

void Display::SDL2Text::setColor(const Display::Color &src)
{
    this->color = colorToSDLColor(src);
    if (this->surface)
        SDL_FreeSurface(this->surface);
    this->surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->color);
    if (!this->surface) {
        SDL_Log("Unable to create text: %s", TTF_GetError());
        SDL_Quit();
        exit(84);
    }

    if (this->texture)
        SDL_DestroyTexture(this->texture);
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (!this->texture) {
        SDL_Log("Unable to create texture: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
}

void Display::SDL2Text::setPosition(const Display::Vector2f &src)
{
    this->position = src;
}

Display::Vector2f Display::SDL2Text::getPosition() const
{
    return this->position;
}

void Display::SDL2Text::move(const Display::Vector2f &offset)
{
    this->position.x += offset.x;
    this->position.y += offset.y;
}

SDL_Texture &Display::SDL2Text::getSDLText()
{
    return *this->texture;
}

int Display::SDL2Text::getFontSize() const
{
    return this->fontSize;
}
