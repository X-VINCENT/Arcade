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
#include <unistd.h>

#define WINDOW_WIDTH 50
#define WINDOW_HEIGHT 20
#define FPS 60

// Spritesheet
#define SNAKE_RECT_UP_RIGHT {0, 0, 1, 1}
#define SNAKE_RECT_HORIZONTAL {0, 1, 1, 1}
#define SNAKE_RECT_UP_LEFT {0, 2, 1, 1}
#define SNAKE_RECT_VERTICAL {1, 2, 1, 1}
#define SNAKE_RECT_DOWN_RIGHT {1, 0, 1, 1}
#define SNAKE_RECT_DOWN_LEFT {2, 2, 1, 1}

#define SNAKE_RECT_HEAD_UP {0, 3, 1, 1}
#define SNAKE_RECT_HEAD_RIGHT {0, 4, 1, 1}
#define SNAKE_RECT_HEAD_LEFT {1, 3, 1, 1}
#define SNAKE_RECT_HEAD_DOWN {1, 4, 1, 1}

#define SNAKE_RECT_TAIL_UP {2, 3, 1, 1}
#define SNAKE_RECT_TAIL_RIGHT {2, 4, 1, 1}
#define SNAKE_RECT_TAIL_LEFT {3, 3, 1, 1}
#define SNAKE_RECT_TAIL_DOWN {3, 4, 1, 1}

#define FOOD_RECT {3, 0, 1, 1}

// Positions
#define MAP_POS {0, 0}
#define SCORE_POS {0, 0}

Game::Snake::Snake(Display::IFactory &factory)
{
    this->window = factory.createWindow("Snake", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->mainTexture = factory.createTexture('#', "assets/snake/snake.png");
    this->mapTexture = factory.createTexture(' ', "assets/snake/map.png");
    this->arialFont = factory.createFont("assets/snake/arial.ttf");
    this->renderClock = factory.createClock();
    this->snakeClock = factory.createClock();

    this->map = factory.createSprite(
        *this->mapTexture,
        {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT},
        MAP_POS
    );

    this->snake.push_back(factory.createSprite(
        *this->mainTexture,
        SNAKE_RECT_HEAD_RIGHT,
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}
    ));
    for (size_t i = 0; i < 2; i++) {
        this->snake.push_back(factory.createSprite(
            *this->mainTexture,
            SNAKE_RECT_HORIZONTAL,
            {(float)WINDOW_WIDTH / 2 - i - 1, WINDOW_HEIGHT / 2}
        ));
    }
    this->snake.push_back(factory.createSprite(
        *this->mainTexture,
        SNAKE_RECT_TAIL_RIGHT,
        {(float)WINDOW_WIDTH / 2 - 3, WINDOW_HEIGHT / 2}
    ));

    this->food = factory.createSprite(
        *this->mainTexture,
        FOOD_RECT,
        {(float)(rand() % WINDOW_WIDTH) * 1,
        (float)(rand() % WINDOW_HEIGHT) * 1}
    );

    this->scoreText = factory.createText(
        "Score: 0",
        *this->arialFont,
        Display::Color::WHITE,
        SCORE_POS
    );

    this->gameOverText = factory.createText(
        "GAME OVER",
        *this->arialFont,
        Display::Color::RED,
        {WINDOW_WIDTH / 2 - 5, WINDOW_HEIGHT / 2 - 5}
    );

    this->restartText = factory.createText(
        "Press R to restart",
        *this->arialFont,
        Display::Color::WHITE,
        {WINDOW_WIDTH / 2 - 10, WINDOW_HEIGHT / 2 + 5}
    );

    this->direction = Game::Direction::RIGHT;
    this->setState(Game::State::GAME);
    this->score = 0;
    this->snakeSpeed = 1;
}

Game::Snake::~Snake()
{
}

void Game::Snake::handleEvents()
{
    if (!this->window)
        return;
    this->event = this->window->getEvent();
    this->snakeSpeed = 1;

    switch (event) {
        case Display::Event::Close:
            this->setState(Game::State::END);
            break;
        case Display::Event::Escape:
            this->setState(Game::State::MENU);
            break;
        case Display::Event::Q:
        case Display::Event::Left:
            if (this->direction == Game::Direction::RIGHT)
                break;
            this->direction = Game::Direction::LEFT;
            break;
        case Display::Event::D:
        case Display::Event::Right:
            if (this->direction == Game::Direction::LEFT)
                break;
            this->direction = Game::Direction::RIGHT;
            break;
        case Display::Event::Z:
        case Display::Event::Up:
            if (this->direction == Game::Direction::DOWN)
                break;
            this->direction = Game::Direction::UP;
            break;
        case Display::Event::S:
        case Display::Event::Down:
            if (this->direction == Game::Direction::UP)
                break;
            this->direction = Game::Direction::DOWN;
            break;
        case Display::Event::Space:
            this->snakeSpeed = 10;
            break;
        default:
            break;
    }
}

void Game::Snake::moveSnake()
{
    Display::Vector2f prevPos = this->snake[0]->getPosition();
    Display::Vector2f currentPos = {0, 0};
    Display::Vector2f nextPos = {0, 0};
    Display::Vector2f offsetPrev = {0, 0};
    Display::Vector2f offsetNext = {0, 0};

    if (this->snakeClock->getElapsedTime() < 100 / this->snakeSpeed)
        return;
    switch (this->direction) {
        case Game::Direction::LEFT:
            this->snake[0]->setRect(SNAKE_RECT_HEAD_LEFT);
            this->snake[0]->move({-1, 0});
            break;
        case Game::Direction::RIGHT:
            this->snake[0]->setRect(SNAKE_RECT_HEAD_RIGHT);
            this->snake[0]->move({1, 0});
            break;
        case Game::Direction::UP:
            this->snake[0]->setRect(SNAKE_RECT_HEAD_UP);
            this->snake[0]->move({0, -1});
            break;
        case Game::Direction::DOWN:
            this->snake[0]->setRect(SNAKE_RECT_HEAD_DOWN);
            this->snake[0]->move({0, 1});
            break;
        default:
            break;
    }

    for (size_t i = 1; i < this->snake.size(); i++) {
        currentPos = this->snake[i]->getPosition();
        this->snake[i]->setPosition(prevPos);
        prevPos = currentPos;
    }

    for (size_t i = 1; i < this->snake.size() - 1; i++) {
        prevPos = this->snake[i - 1]->getPosition();
        currentPos = this->snake[i]->getPosition();
        nextPos = this->snake[i + 1]->getPosition();
        offsetPrev = {prevPos.x - currentPos.x, prevPos.y - currentPos.y};
        offsetNext = {nextPos.x - currentPos.x, nextPos.y - currentPos.y};

        if (offsetPrev.x == 0) {
            if (offsetNext.x == 0) {
                this->snake[i]->setRect(SNAKE_RECT_VERTICAL);
            } else if (offsetNext.x == 1) {
                if (offsetPrev.y == 1)
                    this->snake[i]->setRect(SNAKE_RECT_UP_RIGHT);
                else
                    this->snake[i]->setRect(SNAKE_RECT_DOWN_RIGHT);
            } else {
                if (offsetPrev.y == 1)
                    this->snake[i]->setRect(SNAKE_RECT_UP_LEFT);
                else
                    this->snake[i]->setRect(SNAKE_RECT_DOWN_LEFT);
            }
        } else if (offsetPrev.y == 0) {
            if (offsetNext.y == 0) {
                this->snake[i]->setRect(SNAKE_RECT_HORIZONTAL);
            } else if (offsetNext.y == 1) {
                if (offsetPrev.x == 1)
                    this->snake[i]->setRect(SNAKE_RECT_UP_RIGHT);
                else
                    this->snake[i]->setRect(SNAKE_RECT_UP_LEFT);
            } else {
                if (offsetPrev.x == 1)
                    this->snake[i]->setRect(SNAKE_RECT_DOWN_RIGHT);
                else
                    this->snake[i]->setRect(SNAKE_RECT_DOWN_LEFT);
            }
        }
    }
    prevPos = this->snake[this->snake.size() - 2]->getPosition();
    currentPos = this->snake[this->snake.size() - 1]->getPosition();
    offsetPrev = {prevPos.x - currentPos.x, prevPos.y - currentPos.y};
    if (offsetPrev.x == 0) {
        if (offsetPrev.y == 1)
            this->snake[this->snake.size() - 1]->setRect(SNAKE_RECT_TAIL_DOWN);
        else
            this->snake[this->snake.size() - 1]->setRect(SNAKE_RECT_TAIL_UP);
    } else {
        if (offsetPrev.x == 1)
            this->snake[this->snake.size() - 1]->setRect(SNAKE_RECT_TAIL_RIGHT);
        else
            this->snake[this->snake.size() - 1]->setRect(SNAKE_RECT_TAIL_LEFT);
    }
    this->snakeClock->restart();
}

void Game::Snake::handleEat(Display::IFactory &factory)
{
    if (this->snake[0]->getPosition().x == this->food->getPosition().x &&
        this->snake[0]->getPosition().y == this->food->getPosition().y) {
        this->snake.push_back(factory.createSprite(
            *this->mainTexture,
            {0, 0, 1, 1},
            this->snake[this->snake.size() - 2]->getPosition()
        ));
        this->food->setPosition({
            (float)(rand() % WINDOW_WIDTH) * 1,
            (float)(rand() % WINDOW_HEIGHT) * 1
        });
        this->score++;
        this->scoreText->setText("Score: " + std::to_string(this->score));
    }
}

void Game::Snake::handleCollision()
{
    Display::Vector2f headPos;
    Display::Vector2f bodyPos;

    if (this->snake.size() > 4) {
        for (size_t i = 2; i < this->snake.size(); i++) {
            headPos = this->snake[0]->getPosition();
            bodyPos = this->snake[i]->getPosition();
            if (headPos.x == bodyPos.x && headPos.y == bodyPos.y)
                this->setState(Game::State::END);
        }
    }
    if (this->snake.size() >= WINDOW_WIDTH * WINDOW_HEIGHT)
        this->setState(Game::State::END);
    headPos = this->snake[0]->getPosition();
    if (headPos.x < 0)
        this->snake[0]->setPosition({(float)WINDOW_WIDTH - 1, headPos.y});
    if (headPos.x >= WINDOW_WIDTH)
        this->snake[0]->setPosition({0, headPos.y});
    if (headPos.y < 0)
        this->snake[0]->setPosition({headPos.x, (float)WINDOW_HEIGHT - 1});
    if (headPos.y >= WINDOW_HEIGHT)
        this->snake[0]->setPosition({headPos.x, 0});
}

void Game::Snake::updateWindow()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();

    this->window->draw(*this->map);
    for (auto &sprite : this->snake)
        this->window->draw(*sprite);
    this->window->draw(*this->food);
    this->window->draw(*this->scoreText);

    this->window->display();
    this->renderClock->restart();
}

void Game::Snake::updateWindowEnd()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();

    this->window->draw(*this->map);
    this->window->draw(*this->gameOverText);
    this->window->draw(*this->restartText);

    this->window->display();
    this->renderClock->restart();
}

void Game::Snake::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            this->handleEat(factory);
            this->moveSnake();
            this->handleCollision();
            this->updateWindow();
            break;
        case Game::State::END:
            this->updateWindowEnd();
            break;
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

Display::Event Game::Snake::getEvent() const
{
    return this->event;
}

void Game::Snake::stop()
{
    this->mapTexture.reset();
    this->mainTexture.reset();
    this->arialFont.reset();
    this->renderClock.reset();
    this->snakeClock.reset();
    this->map.reset();
    for (auto &sprite : this->snake)
        sprite.reset();
    this->food.reset();
    this->scoreText.reset();
    this->window->close();
    this->window.reset();
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory)
{
    return std::make_unique<Game::Snake>(factory);
}
