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

Game::Centipede::Centipede(Display::IFactory &factory)
{
    this->window = factory.createWindow("Centipede", 60, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->playerTexture = factory.createTexture('O', "assets/centipede/player.png");
    this->player = factory.createSprite(
        *this->playerTexture,
        {0, 0, 1, 1},
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT - 5}
    );
    this->projectileTexture = factory.createTexture('o', "assets/centipede/body.png");
    this->projectile = factory.createSprite(
        *this->projectileTexture,
        {0, 0, 1, 1},
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT - 3}
    );
    this->centipedeTexture = factory.createTexture('#', "assets/centipede/body.png");

    for (size_t i = 0; i < 10; i++) {
        this->centipede.push_back(factory.createSprite(
            *this->centipedeTexture,
            {0, 0, 1, 1},
            {(float)WINDOW_WIDTH / 2 + i - 5, 0}
        ));
    }

    this->obstacleTexture = factory.createTexture('X', "assets/centipede/body.png");
    for (size_t i = 0; i < 10; i++) {
        this->obstacles.push_back(factory.createSprite(
            *this->obstacleTexture,
            {0, 0, 1, 1},
            {(float)(rand() % (WINDOW_WIDTH - 2) + 1), (float)(rand() % (WINDOW_HEIGHT - 2) + 1)}
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
        case Display::Event::Space:
            if (this->canShoot == true)
                this->shoot();
            break;
        default:
            break;
    }
}

void Game::Centipede::updateWindow()
{
    this->window->clear();
    for (auto &sprite : this->obstacles) {
        this->window->draw(*sprite);
    }
    this->window->draw(*this->player);
    this->window->draw(*this->projectile);
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
            this->handleCollision();
            this->moveCentipede();
            this->updateShoot();
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
            if (this->player->getPosition().x > 1)
                this->player->move({-1, 0});
            break;
        case Game::Direction::RIGHT:
            if (this->player->getPosition().x < WINDOW_WIDTH - 1)
                this->player->move({1, 0});
            break;
        case Game::Direction::UP:
            if (this->player->getPosition().y > WINDOW_HEIGHT * 0.8)
                this->player->move({0, -1});
            break;
        case Game::Direction::DOWN:
            if (this->player->getPosition().y < WINDOW_HEIGHT - 1)
                this->player->move({0, 1});
            break;
        default:
            break;
    }
}

void Game::Centipede::moveCentipede()
{
    if (this->centipedeDirection == Game::Direction::LEFT) {
        if (this->centipede[0]->getPosition().x > 0)
            this->centipede[0]->move({-1, 0});
        else {
            this->centipedeDirection = Game::Direction::RIGHT;
            this->centipede[0]->move({0, 1});
        }
    } else if (this->centipedeDirection == Game::Direction::RIGHT) {
        if (this->centipede[0]->getPosition().x < WINDOW_WIDTH - 1)
            this->centipede[0]->move({1, 0});
        else {
            this->centipedeDirection = Game::Direction::LEFT;
            this->centipede[0]->move({0, 1});
        }
    }

    for (size_t i = this->centipede.size() - 1; i > 0; i--) {
        Display::Vector2f pos = this->centipede[i - 1]->getPosition();
        this->centipede[i]->setPosition(pos);
    }

    if (this->centipede[0]->getPosition().y > WINDOW_HEIGHT)
        this->setState(Game::State::END);
}

void Game::Centipede::handleCollision()
{
    for (auto &sprite : this->centipede) {
        if (this->player->getPosition().x == sprite->getPosition().x &&
            this->player->getPosition().y == sprite->getPosition().y) {
            this->setState(Game::State::END);
        }
    }
    for (auto &obstacle : this->obstacles) {
        if (this->centipede[0]->getPosition().x == obstacle->getPosition().x &&
            this->centipede[0]->getPosition().y == obstacle->getPosition().y) {
            if (this->centipedeDirection == Game::Direction::LEFT)
                this->centipedeDirection = Game::Direction::RIGHT;
            else
                this->centipedeDirection = Game::Direction::LEFT;
            this->centipede[0]->move({0, 1});
        }
    }
}

void Game::Centipede::shoot()
{
    this->canShoot = false;
    this->projectile->setPosition(this->player->getPosition());
}

void Game::Centipede::updateShoot()
{
    if (this->canShoot == false)
        return;
    if (this->projectile->getPosition().y == 0) {
        this->canShoot = true;
        return;
    }

    this->projectile->move({0, -1});
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

const std::string &Game::Centipede::getName() const
{
    return this->name;
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory)
{
    return std::make_unique<Game::Centipede>(factory);
}