/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include <iostream>

Game::Snake::Snake() : name("Snake")
{
}

Game::Snake::~Snake()
{
}

void Game::Snake::setFunctions(
    std::unique_ptr<Display::IWindow> (*window)(),
    std::unique_ptr<Display::ISprite> (*sprite)(),
    std::unique_ptr<Display::ITexture> (*texture)()
)
{
    this->windowPtr = window();
    this->spritePtr = sprite();
    this->texturePtr = texture();
}

void Game::Snake::init()
{
    this->windowPtr->create("Snake", 60, 100, 100);
    this->snakeTexture = std::move(texturePtr);
    this->foodTexture = std::move(texturePtr);
    this->snakeTexture->load('#', "assets/snake/body.png");
    this->foodTexture->load('o', "assets/snake/food.png");
    this->texturePtr->load('#', "assets/snake/body.png");
    std::vector<Display::IVector2f> positions = {
        {50, 50},
        {40, 50},
        {30, 50}
    };
    Display::IIntRect rect{0, 0, 10, 10};
    for (size_t i = 0; i < this->snake.size(); i++)
        this->snake[i]->create(std::move(this->texturePtr), rect, positions[i]);
    this->food = std::move(spritePtr);
    this->food->create(std::move(this->foodTexture), rect, Display::IVector2f{100, 100});
}

void Game::Snake::update()
{
    Display::KeyType key = this->windowPtr->getEvent()->getType();

    switch (key) {
        case Display::KeyType::Q:
        case Display::KeyType::Left:
            this->snake[0]->move({-10, 0});
            break;
        case Display::KeyType::D:
        case Display::KeyType::Right:
            this->snake[0]->move({10, 0});
            break;
        case Display::KeyType::Z:
        case Display::KeyType::Up:
            this->snake[0]->move({0, -10});
            break;
        case Display::KeyType::S:
        case Display::KeyType::Down:
            this->snake[0]->move({0, 10});
            break;
        default:
            break;
    }

    for (size_t i = this->snake.size() - 1; i > 0; i--)
        this->snake[i]->setPosition(this->snake[i - 1]->getPosition());

    if (this->snake[0]->getPosition().x == this->food->getPosition().x &&
        this->snake[0]->getPosition().y == this->food->getPosition().y) {
        this->snake.push_back(std::move(spritePtr));
        this->snake.back()->create(std::move(this->snakeTexture), Display::IIntRect{0, 0, 10, 10}, this->snake[this->snake.size() - 2]->getPosition());
        this->food->setPosition({20, 30});
    }

    this->windowPtr->clear();
    for (auto &sprite : this->snake) {
        this->windowPtr->draw(sprite);
    }
    this->windowPtr->draw(this->food);
    this->windowPtr->display();
}

void Game::Snake::stop()
{
    this->windowPtr->close();
}

const std::string &Game::Snake::getName() const
{
    return this->name;
}

extern "C" std::unique_ptr<Game::IGameModule> createGame()
{
    return std::make_unique<Game::Snake>();
}
