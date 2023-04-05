/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <fstream>
#include <sstream>

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 30
#define FPS 60

Core::Menu::Menu(
    Display::IFactory &factory,
    std::vector<std::string> const &games,
    std::vector<std::string> const &graphics,
    std::string username
)
{
    this->games = games;
    this->graphics = graphics;
    this->username = username;
    this->isWarning = false;
    this->init(factory);
}

Core::Menu::~Menu()
{
}

void Core::Menu::init(Display::IFactory &factory)
{
    std::string const &titleStr = "Arcade";
    std::string const &gamesTitleStr = "Games";
    std::string const &graphicsTitleStr = "Graphics";
    std::string const &keyInfosStr1 = "Left/Right: Change game  |  Up/Down: Change graphic";
    std::string const &keyInfosStr2 = "Enter:      Select game  |  Comma:   Select graphic";
    std::string const &keyInfosStr3 = "Escape:     Quit";
    std::string const &usernameTitleStr = "Username";

    this->window = factory.createWindow("Menu", FPS, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->renderClock = factory.createClock();

    this->backgroundTexture = factory.createTexture(' ', "assets/menu/background.png");
    this->background = factory.createSprite(
        *this->backgroundTexture,
        {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT},
        {0, 0}
    );

    this->arialFont = factory.createFont("assets/menu/arial.ttf");
    this->title = factory.createText(
        titleStr,
        *this->arialFont,
        Display::Color::BLUE,
        {(float)WINDOW_WIDTH / 2 - titleStr.size() / 2, 1}
    );

    this->gamesTitle = factory.createText(
        gamesTitleStr,
        *this->arialFont,
        Display::Color::CYAN,
        {(float)WINDOW_WIDTH / 2 - 10 - gamesTitleStr.size() / 2, 5}
    );

    this->graphicsTitle = factory.createText(
        graphicsTitleStr,
        *this->arialFont,
        Display::Color::CYAN,
        {(float)WINDOW_WIDTH / 2 + 10 + graphicsTitleStr.size() / 2, 5}
    );

    for (int i = 0; i < this->games.size(); i++) {
        this->gamesTexts.push_back(factory.createText(
            games[i],
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 - 10, (float)6 + i}
        ));
    }

    for (int i = 0; i < this->graphics.size(); i++) {
        this->graphicsTexts.push_back(factory.createText(
            graphics[i],
            *this->arialFont,
            i == 0 ? Display::Color::RED : Display::Color::WHITE,
            {(float)WINDOW_WIDTH / 2 + 12 + graphicsTitleStr.size() / 2, (float)6 + i}
        ));
    }

    this->keyInfos1 = factory.createText(
        keyInfosStr1,
        *this->arialFont,
        Display::Color::WHITE,
        {0, WINDOW_HEIGHT - 4}
    );
    this->keyInfos2 = factory.createText(
        keyInfosStr2,
        *this->arialFont,
        Display::Color::WHITE,
        {0, WINDOW_HEIGHT - 3}
    );
    this->keyInfos3 = factory.createText(
        keyInfosStr3,
        *this->arialFont,
        Display::Color::WHITE,
        {0, WINDOW_HEIGHT - 2}
    );

    this->usernameTitle = factory.createText(
        usernameTitleStr,
        *this->arialFont,
        Display::Color::BLUE,
        {(float)WINDOW_WIDTH / 2 - 4, WINDOW_HEIGHT / 2 - 2}
    );
    this->usernameText = factory.createText(
        this->username,
        *this->arialFont,
        Display::Color::WHITE,
        {(float)WINDOW_WIDTH / 2 - 3, WINDOW_HEIGHT / 2}
    );

    this->warningText = factory.createText(
        "No warning",
        *this->arialFont,
        Display::Color::RED,
        {0, 0}
    );

    this->initScores(factory);
}

std::vector<std::string> splitLine(std::string const &str, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delim))
        result.push_back(item);
    return result;
}
#include <iostream>
void Core::Menu::initScores(Display::IFactory &factory)
{
    for (auto &game : this->games) {
        std::tuple<std::string, std::string, int> bestScore = {game, "", 0};
        this->bestScores.push_back(bestScore);
    }

    std::ifstream file("scores.txt");
    if (!file.is_open())
        return;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> splittedLine = splitLine(line, ':');
        std::tuple<std::string, std::string, int> score = {splittedLine[0], splittedLine[1], std::stoi(splittedLine[2])};

        for (int i = 0; i < this->bestScores.size(); i++) {
            if (std::get<0>(this->bestScores[i]) == std::get<0>(score)) {
                if (std::get<2>(this->bestScores[i]) < std::get<2>(score))
                    this->bestScores[i] = score;
                break;
            }
        }
    }
    file.close();

    int i = 0;
    for (auto &game : this->games) {
        this->scoresNamesTexts.push_back(factory.createText(
            game,
            *this->arialFont,
            Display::Color::BLUE,
            {1, (float)3 + 3 * i}
        ));
        this->scoresTexts.push_back(factory.createText(
            std::get<1>(this->bestScores[i]) == "" ? "No score set" : std::get<1>(this->bestScores[i]) + ": " + std::to_string(std::get<2>(this->bestScores[i])),
            *this->arialFont,
            Display::Color::WHITE,
            {2, (float)4 + 3 * i}
        ));
        i++;
    }
}

void Core::Menu::setSelectedGame(int selectedGame)
{
    for (int i = 0; i < this->gamesTexts.size(); i++)
        this->gamesTexts[i]->setColor(i == selectedGame ? Display::Color::RED : Display::Color::WHITE);
}

void Core::Menu::setSelectedGraphic(int selectedGraphic)
{
    for (int i = 0; i < this->graphicsTexts.size(); i++)
        this->graphicsTexts[i]->setColor(i == selectedGraphic ? Display::Color::RED : Display::Color::WHITE);
}

void Core::Menu::setUsername(std::string const &username)
{
    this->username = username;
    this->usernameText->setText(username);
    this->usernameText->setPosition({
        (float)WINDOW_WIDTH / 2 - username.size() / 2,
        WINDOW_HEIGHT / 2
    });
}

void Core::Menu::setWarning(std::string const &warning)
{
    this->warningText->setText(warning);
}

void Core::Menu::setIsWarning(bool isWarning)
{
    this->isWarning = isWarning;
}

Display::Event Core::Menu::getEvent() const
{
    return this->window->getEvent();
}

void Core::Menu::render()
{
    if (this->renderClock->getElapsedTime() < 1000 / FPS)
        return;
    this->window->clear();

    this->window->draw(*this->background);
    this->window->draw(*this->title);
    this->window->draw(*this->gamesTitle);
    this->window->draw(*this->graphicsTitle);
    for (auto &gameText : this->gamesTexts)
        this->window->draw(*gameText);
    for (auto &graphicText : this->graphicsTexts)
        this->window->draw(*graphicText);
    this->window->draw(*this->keyInfos1);
    this->window->draw(*this->keyInfos2);
    this->window->draw(*this->keyInfos3);
    this->window->draw(*this->usernameTitle);
    this->window->draw(*this->usernameText);
    if (this->isWarning)
        this->window->draw(*this->warningText);
    for (auto &scoreNameText : this->scoresNamesTexts)
        this->window->draw(*scoreNameText);
    for (auto &scoreText : this->scoresTexts)
        this->window->draw(*scoreText);

    this->window->display();
    this->renderClock->restart();
}

void Core::Menu::stop()
{
    this->renderClock.reset();
    this->backgroundTexture.reset();
    this->background.reset();
    this->arialFont.reset();
    this->title.reset();
    this->gamesTitle.reset();
    this->graphicsTitle.reset();
    for (auto &gameText : this->gamesTexts)
        gameText.reset();
    gamesTexts.clear();
    for (auto &graphicText : this->graphicsTexts)
        graphicText.reset();
    graphicsTexts.clear();
    this->keyInfos1.reset();
    this->keyInfos2.reset();
    this->keyInfos3.reset();
    this->usernameTitle.reset();
    this->usernameText.reset();
    this->warningText.reset();
    for (auto &scoreNameText : this->scoresNamesTexts)
        scoreNameText.reset();
    scoresNamesTexts.clear();
    for (auto &scoreText : this->scoresTexts)
        scoreText.reset();
    scoresTexts.clear();
    this->window->close();
    this->window.reset();
}

void Core::Menu::updateFactory(Display::IFactory &factory)
{
    gamesTexts.clear();
    graphicsTexts.clear();
    this->init(factory);
}
