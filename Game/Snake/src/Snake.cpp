/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include <iostream>
#include "SDL2Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game::Snake::Snake(Display::IFactory &factory)
{
    this->window = factory.createWindow("Snake", 60, 100, 100);
    this->snakeTexture = factory.createTexture('#', "assets/snake/body.png");
    this->foodTexture = factory.createTexture('o', "assets/snake/food.png");

    this->food = factory.createSprite(
        *this->foodTexture,
        {0, 0, 10, 10},
        {30, 40}
    );

    for (size_t i = 0; i < 3; i++) {
        this->snake.push_back(factory.createSprite(
            *this->snakeTexture,
            {0, 0, 10, 10},
            {(float)10 * i, 0}
        ));
    }

    this->direction = Game::Direction::RIGHT;
    this->setState(Game::State::GAME);
}

Game::Snake::~Snake()
{
}

void Game::Snake::handleEvents()
{
    Display::Event event = this->window->getEvent();

    switch (event) {
        case Display::Event::Close:
            this->setState(Game::State::END);
            break;
        case Display::Event::Escape:
            this->setState(Game::State::MENU);
            break;
        case Display::Event::Q:
        case Display::Event::Left:
            this->direction = Game::Direction::LEFT;
            break;
        case Display::Event::D:
        case Display::Event::Right:
            this->direction = Game::Direction::RIGHT;
            break;
        case Display::Event::Z:
        case Display::Event::Up:
            this->direction = Game::Direction::UP;
            break;
        case Display::Event::S:
        case Display::Event::Down:
            this->direction = Game::Direction::DOWN;
            break;
        default:
            break;
    }
}

void Game::Snake::moveSnake()
{
    switch (this->direction) {
        case Game::Direction::LEFT:
            this->snake[0]->move({-10, 0});
            break;
        case Game::Direction::RIGHT:
            this->snake[0]->move({10, 0});
            break;
        case Game::Direction::UP:
            this->snake[0]->move({0, -10});
            break;
        case Game::Direction::DOWN:
            this->snake[0]->move({0, 10});
            break;
        default:
            break;
    }

    for (size_t i = this->snake.size() - 1; i > 0; i--)
        this->snake[i]->setPosition(this->snake[i - 1]->getPosition());
}

void Game::Snake::handleEat(Display::IFactory &factory)
{
    if (this->snake[0]->getPosition().x == this->food->getPosition().x &&
        this->snake[0]->getPosition().y == this->food->getPosition().y) {
        this->snake.push_back(factory.createSprite(
            *this->snakeTexture,
            {0, 0, 10, 10},
            this->snake[this->snake.size() - 2]->getPosition()
        ));
        this->food->setPosition({
            (float)(rand() % 100) * 10,
            (float)(rand() % 100) * 10
        });
    }
}

void Game::Snake::handleCollision()
{
    /* if (this->snake[0]->getPosition().x < 0 ||
        this->snake[0]->getPosition().x > 1000 ||
        this->snake[0]->getPosition().y < 0 ||
        this->snake[0]->getPosition().y > 1000)
        this->setState(Game::State::END); */
}

void Game::Snake::updateWindow()
{
    this->window->clear();

    for (auto &sprite : this->snake)
        this->window->draw(*sprite);
    this->window->draw(*this->food);

    this->window->display();
}

void Game::Snake::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            this->moveSnake();
            this->handleEat(factory);
            this->handleCollision();
            this->updateWindow();
        // case Game::State::END:
        //     this->window->close();
        default:
            break;
    }
}

void Game::Snake::setState(Game::State state)
{
    this->state = state;
}

Game::State Game::Snake::getState() const
{
    return this->state;
}

void Game::Snake::run(Display::IFactory &factory)
{
    while (this->getState() != Game::State::END)
        this->update(factory);
    this->stop();
}

void Game::Snake::stop()
{
    if (!this->window->isOpen())
        return;
    this->window->close();
}

const std::string &Game::Snake::getName() const
{
    return this->name;
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory)
{
    return std::make_unique<Game::Snake>(factory);
}
