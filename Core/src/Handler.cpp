/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** Core
*/

#include "Handler.hpp"

Core::Handler::Handler(std::string const &displayLibPath)
    : displayLoader(displayLibPath), gameLoader("lib/arcade_snake.so")
{
    this->games = {
        {
            {"name", "Snake"},
            {"path", "lib/arcade_snake.so"}
        },
        {
            {"name", "Centipede"},
            {"path", "lib/arcade_centipede.so"}
        }
    };
    this->graphics = {
        {
            {"name", "Ncurses"},
            {"path", "lib/arcade_ncurses.so"}
        },
        {
            {"name", "SDL2"},
            {"path", "lib/arcade_sdl2.so"}
        },
        {
            {"name", "SFML"},
            {"path", "lib/arcade_sfml.so"}
        }
    };
    for (auto &game : games)
        this->gameNames.push_back(game["name"]);

    for (auto &graphic : graphics)
        this->graphicNames.push_back(graphic["name"]);
    this->selectedGame = 0;
    this->selectedGraphic = 0;
    this->createFactory();
    this->isRunning = true;
    this->current_state = MENU;
    this->menu = std::make_unique<Core::Menu>(*this->factory, this->gameNames, this->graphicNames);
}

Core::Handler::~Handler()
{
}

void Core::Handler::createFactory()
{
    std::string const &createFactoryFn = "createFactory";
    using factoryFnPtr = std::unique_ptr<Display::IFactory> (*)();
    factoryFnPtr createFactoryPtr = this->displayLoader.template getInstance<factoryFnPtr>(createFactoryFn);
    try {
        this->factory = createFactoryPtr();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Core::Handler::createGame()
{
    std::string const &createGameFn = "createGame";
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
    gameFnPtr createGamePtr = nullptr;
    try {
        createGamePtr = this->gameLoader.template getInstance<gameFnPtr>(createGameFn);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    this->game = createGamePtr(*this->factory);
}

void Core::Handler::loop()
{
    while (this->isRunning) {
        switch (this->current_state) {
            case MENU:
                try {
                    if (menu == nullptr)
                        throw std::runtime_error("Menu is not initialized");
                } catch (std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
                this->handleMenuEvents();
                if (this->current_state == GAME)
                    break;
                this->menu->render();
                break;
            case GAME:
                try {
                    if (game == nullptr)
                        throw std::runtime_error("Game is not initialized");
                } catch (std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
                this->handleGameEvents();
                if (this->current_state == MENU)
                    break;
                this->game->update(*this->factory);
                break;
        }
    }
    switch (this->current_state) {
        case MENU:
            this->menu->stop();
            break;
        case GAME:
            this->game->stop();
            break;
    }
}

void Core::Handler::handleGameEvents()
{
    Display::Event event = game->getEvent();

    switch (event) {
        case Display::Event::O:
            this->selectedGraphic++;
            if (this->selectedGraphic >= this->graphicNames.size())
                this->selectedGraphic = 0;
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->displayLoader.changeLib(this->graphics[this->selectedGraphic]["path"]);
            this->createFactory();
            this->createGame();
            break;
        case Display::Event::L:
            this->selectedGraphic--;
            if (this->selectedGraphic < 0)
                this->selectedGraphic = this->graphicNames.size() - 1;
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->displayLoader.changeLib(this->graphics[this->selectedGraphic]["path"]);
            this->createFactory();
            this->createGame();
            break;
        case Display::Event::M:
            this->selectedGame++;
            if (this->selectedGame >= this->gameNames.size())
                this->selectedGame = 0;
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->gameLoader.changeLib(this->games[this->selectedGame]["path"]);
            this->createFactory();
            this->createGame();
            break;
        case Display::Event::K:
            this->selectedGame--;
            if (this->selectedGame < 0)
                this->selectedGame = this->gameNames.size() - 1;
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->gameLoader.changeLib(this->games[this->selectedGame]["path"]);
            this->createFactory();
            this->createGame();
            break;
        case Display::Event::R:
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->createFactory();
            this->createGame();
            break;
        case Display::Event::Close:
            this->game->stop();
            this->isRunning = false;
            break;
        case Display::Event::Escape:
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->createFactory();
            this->menu = std::make_unique<Core::Menu>(*this->factory, this->gameNames, this->graphicNames);
            this->current_state = MENU;
            break;
        default:
            break;
    }
}

void Core::Handler::handleMenuEvents()
{
    Display::Event event = menu->getEvent();

    switch (event) {
        case Display::Event::Left:
            this->selectedGame += 1;
            break;
        case Display::Event::Right:
            this->selectedGame -= 1;
            break;
        case Display::Event::Up:
            this->selectedGraphic -= 1;
            break;
        case Display::Event::Down:
            this->selectedGraphic += 1;
            break;
        case Display::Event::Enter:
            this->menu->stop();
            if (this->game != nullptr) {
                this->game->stop();
                this->game.reset();
            }
            this->factory.reset();
            this->gameLoader.changeLib(this->games[this->selectedGame]["path"]);
            this->createFactory();
            this->createGame();
            this->current_state = GAME;
            return;
        case Display::Event::Space:
            this->menu->stop();
            this->factory.reset();
            this->displayLoader.changeLib(this->graphics[this->selectedGraphic]["path"]);
            this->createFactory();
            this->menu->updateFactory(*this->factory);
            return;
        case Display::Event::Close:
        case Display::Event::Escape:
            this->isRunning = false;
            break;
        default:
            break;
    }
    if (this->selectedGame < 0)
        this->selectedGame = this->games.size() - 1;
    if (this->selectedGame >= this->games.size())
        this->selectedGame = 0;
    if (this->selectedGraphic < 0)
        this->selectedGraphic = this->graphics.size() - 1;
    if (this->selectedGraphic >= this->graphics.size())
        this->selectedGraphic = 0;
    this->menu->setSelectedGame(this->selectedGame);
    this->menu->setSelectedGraphic(this->selectedGraphic);
}
