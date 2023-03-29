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
    std::unique_ptr<Display::ITexture> (*texture)(),
    std::unique_ptr<Display::ISprite> (*sprite)(),
    std::unique_ptr<Display::IRenderer> (*renderer)()
)
{
    this->createWindow = std::move(window);
    this->createTexture = std::move(texture);
    this->createSprite = std::move(sprite);
    this->createRenderer = std::move(renderer);
}
#include <unistd.h>
void Game::Snake::init()
{
    this->window = this->createWindow();
    this->renderer = this->createRenderer();
    this->window->create("Snake", 60, 100, 100);
    this->renderer->create(this->window);
    this->window->setRenderer(this->renderer->clone());

    this->snakeTexture = this->createTexture();
    this->foodTexture = this->createTexture();
    this->snakeTexture->load('#', "assets/snake/body.png", this->renderer->clone());
    this->renderer->create(this->window);
    this->foodTexture->load('o', "assets/snake/food.png", this->renderer->clone());

    this->food = this->createSprite();
    this->food->create(
        this->foodTexture->clone(),
        {0, 0, 10, 10},
        {30, 40}
    );

    for (size_t i = 0; i < 3; i++) {
        this->snake.push_back(this->createSprite());
        this->snake[i]->create(
            this->snakeTexture->clone(),
            {0, 0, 10, 10},
            {(float)50 + (i * 10), 50}
        );
    }

    this->direction = Game::Direction::RIGHT;
    this->setState(Game::State::GAME);
}

void Game::Snake::handleEvents()
{
    Display::KeyType key = this->window->getEvent()->getType();

    switch (key) {
        case Display::KeyType::Escape:
            this->setState(Game::State::MENU);
            break;
        case Display::KeyType::Q:
        case Display::KeyType::Left:
            this->direction = Game::Direction::LEFT;
            break;
        case Display::KeyType::D:
        case Display::KeyType::Right:
            this->direction = Game::Direction::RIGHT;
            break;
        case Display::KeyType::Z:
        case Display::KeyType::Up:
            this->direction = Game::Direction::UP;
            break;
        case Display::KeyType::S:
        case Display::KeyType::Down:
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

void Game::Snake::handleEat()
{
    if (this->snake[0]->getPosition().x == this->food->getPosition().x &&
        this->snake[0]->getPosition().y == this->food->getPosition().y) {
        this->snake.push_back(this->createSprite());
        this->snake.back()->create(
            this->snakeTexture->clone(),
            {0, 0, 10, 10},
            this->snake[this->snake.size() - 2]->getPosition()
        );
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
        this->window->draw(sprite);
    this->window->draw(this->food);

    this->window->display();
}

void Game::Snake::update()
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            this->moveSnake();
            this->handleEat();
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

void Game::Snake::run()
{
    this->init();
    while (this->getState() != Game::State::END)
        this->update();
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

extern "C" std::unique_ptr<Game::IGameModule> createGame()
{
    return std::make_unique<Game::Snake>();
}
