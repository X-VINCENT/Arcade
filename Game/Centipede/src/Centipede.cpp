/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Centipede.cpp
*/

#include "Centipede.hpp"
#include <iostream>
#include "SDL2Window.hpp"
#include <SDL2/SDL.h>
#include <unistd.h>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 50
#define FPS 60

Game::Centipede::Centipede(Display::IFactory &factory)
{
    this->window = factory.createWindow("Centipede", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->playerTexture = factory.createTexture('O', "assets/centipede/player.png");
    this->player = factory.createSprite(
        *this->playerTexture,
        {0, 0, 1, 1},
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT - 5}
    );
    this->centipedeTexture = factory.createTexture('#', "assets/centipede/body.png");

    for (size_t i = 0; i < 10; i++) {
        this->centipede.push_back(factory.createSprite(
            *this->centipedeTexture,
            {0, 0, 1, 1},
            {(float)WINDOW_WIDTH / 2 + i - 5, 0}
        ));
    }

    this->setState(Game::State::GAME);
}

Game::Centipede::~Centipede()
{
}

void Game::Centipede::handleEvents()
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
            this->movePlayer(Game::Direction::LEFT);
            break;
        case Display::Event::D:
        case Display::Event::Right:
            this->movePlayer(Game::Direction::RIGHT);
            break;
        case Display::Event::Z:
        case Display::Event::Up:
            this->movePlayer(Game::Direction::UP);
            break;
        case Display::Event::S:
        case Display::Event::Down:
            this->movePlayer(Game::Direction::DOWN);
            break;
        default:
            break;
    }
}

void Game::Centipede::updateWindow()
{
    this->window->clear();
    this->window->draw(*this->player);
    for (auto &sprite : this->centipede) {
        this->window->draw(*sprite);
    }
    this->window->display();
}

void Game::Centipede::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            //this->moveCentipede();
            //this->handleCollision();
            this->updateWindow();
            break;
        case Game::State::END:
            this->stop();
            break;
        default:
            break;
    }
}

void Game::Centipede::movePlayer(Game::Direction direction)
{
    switch (direction) {
        case Game::Direction::LEFT:
            break;
        case Game::Direction::RIGHT:
            break;
        case Game::Direction::UP:
            break;
        case Game::Direction::DOWN:
            break;
        default:
            break;
    }
}

void Game::Centipede::moveCentipede()
{
}

void Game::Centipede::handleCollision()
{
}

Game::State Game::Centipede::getState() const
{
    return this->state;
}

void Game::Centipede::run(Display::IFactory &factory)
{
    while (this->getState() != Game::State::END) {
        this->update(factory);
        usleep(100000);
    }
    this->stop();
}

void Game::Centipede::setState(Game::State state)
{
    this->state = state;
}

void Game::Centipede::stop()
{
    this->window->close();
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory)
{
    return std::make_unique<Game::Centipede>(factory);
}