/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Centipede.cpp
*/

#include "Centipede.hpp"
#include <iostream>
#include <unistd.h>

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 20
#define FPS 60
#define CENTIPEDE_SIZE 10
#define OBSTACLES 30
#define OBSTACLE_LIFE 5

Game::Centipede::Centipede(Display::IFactory &factory)
{
    this->window = factory.createWindow("Centipede", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->renderClock = factory.createClock();
    this->playerClock = factory.createClock();
    this->centipedeClock = factory.createClock();
    this->shootClock = factory.createClock();
    this->playerTexture = factory.createTexture('O', "assets/centipede/player.png");
    this->player = factory.createSprite(
        *this->playerTexture,
        {0, 0, 1, 1},
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT - 5}
    );
    this->projectileTexture = factory.createTexture('o', "assets/centipede/shoot.png");
    this->projectile = factory.createSprite(
        *this->projectileTexture,
        {0, 0, 1, 1},
        {(-10, -10)}
    );
    this->centipedeTexture = factory.createTexture('#', "assets/centipede/body.png");

    for (size_t i = 0; i < CENTIPEDE_SIZE; i++) {
        this->centipede.push_back(factory.createSprite(
            *this->centipedeTexture,
            {0, 0, 1, 1},
            {(float)WINDOW_WIDTH / 2 + i - 5, 0}
        ));
    }

    this->obstacleTexture = factory.createTexture('X', "assets/centipede/obstacle.png");
    for (size_t i = 0; i < OBSTACLES; i++) {
        this->obstacles.push_back(factory.createSprite(
            *this->obstacleTexture,
            {0, 0, 1, 1},
            {(float)(rand() % (WINDOW_WIDTH - 2) + 1), (float)(rand() % (WINDOW_HEIGHT - 2) + 1)}
        ));
    }
    for (size_t i = 0; i < OBSTACLES; i++) {
        this->obstaclesLife.push_back(OBSTACLE_LIFE);
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
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();
    for (auto &sprite : this->obstacles)
        this->window->draw(*sprite);
    this->window->draw(*this->player);
    this->window->draw(*this->projectile);
    for (auto &sprite : this->centipede)
        this->window->draw(*sprite);
    this->window->display();
    this->renderClock->restart();
}

void Game::Centipede::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->window->close();
        case Game::State::GAME:
            this->updateShoot();
            this->handleCollision(factory);
            this->moveCentipede();
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
    if (this->playerClock->getElapsedTime() < 100)
        return;
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
    this->playerClock->restart();
}

void Game::Centipede::moveCentipede()
{
    if (this->centipedeClock->getElapsedTime() < 100)
        return;

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

    if (this->centipede[0]->getPosition().y > WINDOW_HEIGHT - 2)
        this->setState(Game::State::END);
    this->centipedeClock->restart();
}

void Game::Centipede::handleCollision(Display::IFactory &factory)
{
    for (auto &sprite : this->centipede) {
        if (this->player->getPosition().x == sprite->getPosition().x &&
            this->player->getPosition().y == sprite->getPosition().y) {
            this->setState(Game::State::END);
        }
    }
    for (auto &obstacle : this->obstacles) {
        for (int i = 0; i < this->centipede.size(); i++) {
            if (this->centipedeDirection == Game::Direction::LEFT &&
                this->centipede[0]->getPosition().x - 1 == obstacle->getPosition().x &&
                this->centipede[0]->getPosition().y == obstacle->getPosition().y) {
                this->centipedeDirection = Game::Direction::RIGHT;
                this->centipede[0]->move({0, 1});
            } else if (this->centipedeDirection == Game::Direction::RIGHT &&
                this->centipede[0]->getPosition().x + 1 == obstacle->getPosition().x &&
                this->centipede[0]->getPosition().y == obstacle->getPosition().y) {
                this->centipedeDirection = Game::Direction::LEFT;
                this->centipede[0]->move({1, 1});
            }
        }
    }
    if (this->projectile->getPosition().x == this->centipede[0]->getPosition().x &&
        this->projectile->getPosition().y == this->centipede[0]->getPosition().y) {
        this->projectile->setPosition({-1, -1});
        this->canShoot = true;
        this->centipede.erase(this->centipede.begin());
    } else if (this->projectile->getPosition().x == this->centipede[this->centipede.size() - 1]->getPosition().x &&
        this->projectile->getPosition().y == this->centipede[this->centipede.size() - 1]->getPosition().y) {
        this->projectile->setPosition({-1, -1});
        this->canShoot = true;
        this->centipede.pop_back();
    }
    for (size_t i = 1; i < this->centipede.size() - 1; i++) {
        if (this->projectile->getPosition().x == this->centipede[i]->getPosition().x &&
            this->projectile->getPosition().y == this->centipede[i]->getPosition().y) {
            this->projectile->setPosition({-1, -1});
            this->canShoot = true;
            this->obstacles.push_back(factory.createSprite(*obstacleTexture, {0, 0, 1, 1}, this->centipede[i]->getPosition()));
            this->obstaclesLife.push_back(5);
            this->centipede.erase(this->centipede.begin() + i);
        }
    }
    for (size_t i = 0; i < this->obstacles.size(); i++) {
        if (this->projectile->getPosition().x == this->obstacles[i]->getPosition().x &&
            this->projectile->getPosition().y == this->obstacles[i]->getPosition().y) {
            this->projectile->setPosition({-1, -1});
            this->canShoot = true;
            this->obstaclesLife[i]--;
            if (this->obstaclesLife[i] == 0) {
                this->obstacles.erase(this->obstacles.begin() + i);
                this->obstaclesLife.erase(this->obstaclesLife.begin() + i);
            }
        }
    }

}

void Game::Centipede::shoot()
{
    this->projectile->setPosition(this->player->getPosition());
    this->canShoot = false;
}

void Game::Centipede::updateShoot()
{
    if (this->shootClock->getElapsedTime() < 100)
        return;
    if (this->projectile->getPosition().y > -1)
        this->projectile->move({0, -1});
    else
        this->canShoot = true;
    this->shootClock->restart();
}

Game::State Game::Centipede::getState() const
{
    return this->state;
}

void Game::Centipede::run(Display::IFactory &factory)
{
    while (this->getState() != Game::State::END)
        this->update(factory);
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
