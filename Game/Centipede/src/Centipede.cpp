/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Centipede.cpp
*/

#include "Centipede.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>

#define WINDOW_WIDTH 40
#define WINDOW_HEIGHT 20
#define FPS 60
#define PLAYER_SPEED 50
#define SHOOT_SPEED 20
#define OBSTACLES 25
#define OBSTACLE_LIFE 5

Game::Centipede::Centipede(Display::IFactory &factory, std::string username)
{
    this->window = factory.createWindow("Centipede", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->renderClock = factory.createClock();
    this->playerClock = factory.createClock();
    this->centipedeClock = factory.createClock();
    this->shootClock = factory.createClock();
    this->scoreClock = factory.createClock();

    this->playerTexture = factory.createTexture('O', "assets/centipede/player.png");
    this->player = factory.createSprite(
        *this->playerTexture,
        {0, 0, 1, 1},
        {(float)WINDOW_WIDTH / 2, WINDOW_HEIGHT - 2}
    );

    this->projectileTexture = factory.createTexture('^', "assets/centipede/shoot.png");
    this->projectile = factory.createSprite(
        *this->projectileTexture,
        {0, 0, 1, 1},
        {(-10, -10)}
    );

    this->centipedeSpeed = 1;
    this->centipedeSize = rand() % 10 + 5;
    this->centipedeTexture = factory.createTexture('#', "assets/centipede/body.png");
    for (size_t i = 0; i < this->centipedeSize; i++) {
        this->centipede.push_back(factory.createSprite(
            *this->centipedeTexture,
            {0, 0, 1, 1},
            {(float)WINDOW_WIDTH / 2 + i - 5, -1}
        ));
    }
    for (size_t i = 0; i < this->centipedeSize; i++) {
        this->centipedeDirections.push_back(Game::Direction::RIGHT);
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

    this->arialFont = factory.createFont("assets/centipede/arial.ttf");

    this->scoreText = factory.createText(
        "Score: 0",
        *this->arialFont,
        Display::Color::WHITE,
        {0, 0}
    );

    this->gameOverText = factory.createText(
        "GAME OVER ! You're a loser !",
        *this->arialFont,
        Display::Color::RED,
        {WINDOW_WIDTH / 2 - 14, WINDOW_HEIGHT / 2 - 5}
    );

    this->restartTextLose = factory.createText(
        "Press R to try again",
        *this->arialFont,
        Display::Color::WHITE,
        {WINDOW_WIDTH / 2 - 10, WINDOW_HEIGHT / 2 + 5}
    );

    this->winText = factory.createText(
        "WELL PLAYED! You've won!",
        *this->arialFont,
        Display::Color::YELLOW,
        {WINDOW_WIDTH / 2 - 12, WINDOW_HEIGHT / 2 - 5}
    );

    this->restartTextWin = factory.createText(
        "Press R to play again",
        *this->arialFont,
        Display::Color::WHITE,
        {WINDOW_WIDTH / 2 - 10, WINDOW_HEIGHT / 2 + 5}
    );

    this->setState(Game::State::GAME);
    this->username = username;
}

Game::Centipede::~Centipede()
{
}

void Game::Centipede::handleEvents()
{
    if (!this->window)
        return;
    this->event = this->window->getEvent();

    switch (event) {
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
    this->scoreText->setText("Score: " + std::to_string(this->score));
    this->window->draw(*this->scoreText);
    this->window->display();
    this->renderClock->restart();
}

void Game::Centipede::updateWindowWin()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();

    this->window->draw(*this->winText);
    this->window->draw(*this->restartTextWin);

    this->window->display();
    this->renderClock->restart();
}

void Game::Centipede::updateWindowLose()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();

    this->window->draw(*this->gameOverText);
    this->window->draw(*this->restartTextLose);

    this->window->display();
    this->renderClock->restart();
}

void Game::Centipede::update(Display::IFactory &factory)
{
    this->handleEvents();
    switch (this->state) {
        case Game::State::MENU:
            this->saveScore();
            this->window->close();
        case Game::State::GAME:
            this->updateShoot();
            this->handleCollision(factory);
            this->moveCentipede(factory);
            this->updateWindow();
            if (this->centipedeNumber == 20) {
                this->setState(Game::State::WIN);
                this->score += 10000;
            }
            if (this->scoreClock->getElapsedTime() > 1000) {
                this->scoreClock->restart();
                this->score += 10;
            }
            break;
        case Game::State::WIN:
            this->saveScore();
            this->updateWindowWin();
            break;
        case Game::State::LOSE:
            this->saveScore();
            this->updateWindowLose();
            break;
        default:
            break;
    }
}

void Game::Centipede::movePlayer(Game::Direction direction)
{
    if (this->playerClock->getElapsedTime() < PLAYER_SPEED)
        return;

    Display::Vector2f new_pos = this->player->getPosition();
    switch (direction) {
        case Game::Direction::LEFT:
            if (new_pos.x > 1)
                new_pos.x -= 1;
            break;
        case Game::Direction::RIGHT:
            if (new_pos.x < WINDOW_WIDTH - 1)
                new_pos.x += 1;
            break;
        case Game::Direction::UP:
            if (new_pos.y > WINDOW_HEIGHT * 0.8)
                new_pos.y -= 1;
            break;
        case Game::Direction::DOWN:
            if (new_pos.y < WINDOW_HEIGHT - 1)
                new_pos.y += 1;
            break;
    }

    bool collision = false;
    for (auto &obstacle : this->obstacles) {
        if (obstacle->getPosition().x == new_pos.x && obstacle->getPosition().y == new_pos.y) {
            collision = true;
            break;
        }
    }

    if (!collision)
        this->player->setPosition(new_pos);

    this->playerClock->restart();
}

void Game::Centipede::moveCentipede(Display::IFactory &factory)
{
    if (this->centipedeClock->getElapsedTime() < 100 / this->centipedeSpeed)
        return;

    for (int i = 0; i < this->centipede.size(); i++) {
        if (centipedeDirections[i] == Game::Direction::LEFT) {
            if (this->centipede[i]->getPosition().x > 0) {
                this->centipede[i]->move({-1, 0});
            } else {
                centipedeDirections[i] = Game::Direction::RIGHT;
                this->centipede[i]->move({-1, 1});
            }
        } else if (centipedeDirections[i] == Game::Direction::RIGHT) {
            if (this->centipede[i]->getPosition().x < WINDOW_WIDTH - 1) {
                this->centipede[i]->move({1, 0});
            } else {
                centipedeDirections[i] = Game::Direction::LEFT;
                this->centipede[i]->move({1, 1});
            }
        }
    }

    if (this->centipede[0]->getPosition().y >= WINDOW_HEIGHT - 1) {
        this->centipede.clear();
        this->centipedeDirections.clear();
        this->centipedeSize = rand() % 10 + 5;
        this->centipedeSpeed = rand() % 3 + 1;
        for (size_t i = 0; i < this->centipedeSize; i++) {
            this->centipede.push_back(factory.createSprite(
                *this->centipedeTexture,
                {0, 0, 1, 1},
                {(float)WINDOW_WIDTH / 2 + i - 5, -1}
            ));
        }
        for (size_t i = 0; i < this->centipedeSize; i++) {
            this->centipedeDirections.push_back(Game::Direction::RIGHT);
        }

        this->score -= 500;
        this->centipedeNumber++;
    }
    this->centipedeClock->restart();
}

void Game::Centipede::handleCollision(Display::IFactory &factory)
{
    for (auto &sprite : this->centipede) {
        if (this->player->getPosition().x == sprite->getPosition().x &&
            this->player->getPosition().y == sprite->getPosition().y) {
            this->setState(Game::State::LOSE);
        }
    }
    for (auto &obstacle : this->obstacles) {
        for (int i = 0; i < this->centipede.size(); i++) {
            if (this->centipedeDirections[i] == Game::Direction::LEFT &&
                this->centipede[i]->getPosition().x == obstacle->getPosition().x &&
                this->centipede[i]->getPosition().y == obstacle->getPosition().y) {
                this->centipedeDirections[i] = Game::Direction::RIGHT;
                this->centipede[i]->move({1, 1});
            } else if (this->centipedeDirections[i] == Game::Direction::RIGHT &&
                this->centipede[i]->getPosition().x == obstacle->getPosition().x &&
                this->centipede[i]->getPosition().y == obstacle->getPosition().y) {
                this->centipedeDirections[i] = Game::Direction::LEFT;
                this->centipede[i]->move({-1, 1});
            }
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
                this->score += 50;
            }
        }
    }
    for (size_t i = 0; i < this->centipede.size(); i++) {
        if (this->projectile->getPosition().x == this->centipede[i]->getPosition().x &&
            this->projectile->getPosition().y == this->centipede[i]->getPosition().y) {
            this->projectile->setPosition({-1, -1});
            this->canShoot = true;
            this->obstacles.push_back(factory.createSprite(*obstacleTexture, {0, 0, 1, 1}, this->centipede[i]->getPosition()));
            this->obstaclesLife.push_back(5);
            this->score += 150;
            this->centipede.erase(this->centipede.begin() + i);
            this->centipedeDirections.erase(this->centipedeDirections.begin() + i);
        }
        if (this->centipede.size() == 0) {
            this->centipede.clear();
            this->centipedeDirections.clear();
            this->centipedeSize = rand() % 10 + 5;
            this->centipedeSpeed = rand() % 3 + 1;
            for (size_t i = 0; i < this->centipedeSize; i++) {
                this->centipede.push_back(factory.createSprite(
                    *this->centipedeTexture,
                    {0, 0, 1, 1},
                    {(float)WINDOW_WIDTH / 2 + i - 5, -1}
                ));
            }
            for (size_t i = 0; i < this->centipedeSize; i++) {
                this->centipedeDirections.push_back(Game::Direction::RIGHT);
            }
            this->centipedeNumber += 1;
            this->score += 1000;
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
    if (this->shootClock->getElapsedTime() < SHOOT_SPEED)
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

Display::Event Game::Centipede::getEvent() const
{
    return this->event;
}

void Game::Centipede::saveScore()
{
    std::ofstream scoresFile("scores.txt", std::ios::app);

    if (!scoresFile.is_open()) {
        std::cerr << "Error: Cannot open scores file." << std::endl;
        return;
    }
    scoresFile << "Centipede:" << this->username << ":" << this->score << std::endl;
    scoresFile.close();
}

void Game::Centipede::setState(Game::State state)
{
    this->state = state;
}

void Game::Centipede::stop()
{
    this->renderClock.reset();
    this->playerClock.reset();
    this->centipedeClock.reset();
    this->shootClock.reset();
    this->scoreClock.reset();
    this->player.reset();
    this->playerTexture.reset();
    this->projectile.reset();
    this->projectileTexture.reset();
    for (auto &sprite : this->centipede)
        sprite.reset();
    this->centipede.clear();
    this->centipedeTexture.reset();
    this->obstacleTexture.reset();
    for (auto &sprite : this->obstacles)
        sprite.reset();
    this->obstacles.clear();
    this->obstaclesLife.clear();
    this->scoreText.reset();
    this->arialFont.reset();
    this->gameOverText.reset();
    this->restartTextLose.reset();
    this->winText.reset();
    this->restartTextWin.reset();
    this->window->close();
    this->window.reset();
}

extern "C" std::unique_ptr<Game::IGameModule> createGame(Display::IFactory &factory, std::string username)
{
    return std::make_unique<Game::Centipede>(factory, username);
}
