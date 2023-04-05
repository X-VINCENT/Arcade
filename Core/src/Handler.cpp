/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** Core
*/

#include "Handler.hpp"

#define MAX_USERNAME_SIZE 32

Core::Handler::Handler(
    std::string const &displayLibPath,
    std::vector<std::map <std::string, std::string>> existingGames,
    std::vector<std::map <std::string, std::string>> existingGraphics
) : games(existingGames),
    graphics(existingGraphics),
    displayLoader(displayLibPath),
    gameLoader(existingGames[0]["path"]),
    username("Player")
{
    for (auto &game : games)
        this->gameNames.push_back(game["name"]);

    for (auto &graphic : graphics)
        this->graphicNames.push_back(graphic["name"]);
    this->selectedGame = 0;
    this->selectedGraphic = 0;
    this->createFactory();
    this->isRunning = true;
    this->current_state = MENU;
    this->menu = std::make_unique<Core::Menu>(*this->factory, this->gameNames, this->graphicNames, this->username);
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
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &, std::string);
    gameFnPtr createGamePtr = nullptr;
    try {
        createGamePtr = this->gameLoader.template getInstance<gameFnPtr>(createGameFn);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    this->game = createGamePtr(*this->factory, this->username);
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
                if (this->isRunning == false)
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
        case Display::Event::Num9:
            this->isRunning = false;
            break;
        case Display::Event::Escape:
            this->game->stop();
            this->game.reset();
            this->factory.reset();
            this->createFactory();
            this->menu = std::make_unique<Core::Menu>(*this->factory, this->gameNames, this->graphicNames, this->username);
            this->current_state = MENU;
            break;
        default:
            break;
    }
}

void Core::Handler::handleUsernameEvents(Display::Event event)
{
   std::map<Display::Event, char> events = {
       {Display::Event::A, 'A'},
       {Display::Event::B, 'B'},
       {Display::Event::C, 'C'},
       {Display::Event::D, 'D'},
       {Display::Event::E, 'E'},
       {Display::Event::F, 'F'},
       {Display::Event::G, 'G'},
       {Display::Event::H, 'H'},
       {Display::Event::I, 'I'},
       {Display::Event::J, 'J'},
       {Display::Event::K, 'K'},
       {Display::Event::L, 'L'},
       {Display::Event::M, 'M'},
       {Display::Event::N, 'N'},
       {Display::Event::O, 'O'},
       {Display::Event::P, 'P'},
       {Display::Event::Q, 'Q'},
       {Display::Event::R, 'R'},
       {Display::Event::S, 'S'},
       {Display::Event::T, 'T'},
       {Display::Event::U, 'U'},
       {Display::Event::V, 'V'},
       {Display::Event::W, 'W'},
       {Display::Event::X, 'X'},
       {Display::Event::Y, 'Y'},
       {Display::Event::Z, 'Z'},
       {Display::Event::Num1, '1'},
       {Display::Event::Num2, '2'},
       {Display::Event::Num3, '3'},
       {Display::Event::Num4, '4'},
       {Display::Event::Num5, '5'},
       {Display::Event::Num6, '6'},
       {Display::Event::Num7, '7'},
       {Display::Event::Num8, '8'},
       {Display::Event::Num9, '9'},
       {Display::Event::Space, ' '},
       {Display::Event::Backspace, '\b'}
   };
   this->menu->setIsWarning(false);
   if (events.find(event) != events.end()) {
       if (events[event] == '\b') {
           if (this->username.size() <= 0) {
                this->menu->setWarning("/!\\ Please enter a username /!\\");
                this->menu->setIsWarning(true);
                return;
           }
            this->username.pop_back();
       } else {
            if (this->username.size() >= MAX_USERNAME_SIZE) {
                this->menu->setWarning("/!\\ Username too long /!\\");
                this->menu->setIsWarning(true);
                return;
           }
           this->username += events[event];
       }
   }
   if (this->username.size() <= 0) {
        this->menu->setWarning("/!\\ Please enter a username /!\\");
        this->menu->setIsWarning(true);
   }
   this->menu->setUsername(this->username);
}

void Core::Handler::handleMenuEvents()
{
    Display::Event event = menu->getEvent();

    switch (event) {
        case Display::Event::Left:
            this->selectedGame -= 1;
            break;
        case Display::Event::Right:
            this->selectedGame += 1;
            break;
        case Display::Event::Up:
            this->selectedGraphic -= 1;
            break;
        case Display::Event::Down:
            this->selectedGraphic += 1;
            break;
        case Display::Event::Enter:
            if (this->username.size() <= 0)
                return;
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
        case Display::Event::Comma:
            if (this->username.size() <= 0)
                return;
            this->menu->stop();
            this->factory.reset();
            this->displayLoader.changeLib(this->graphics[this->selectedGraphic]["path"]);
            this->createFactory();
            this->menu->updateFactory(*this->factory);
            return;
        case Display::Event::Close:
        case Display::Event::Escape:
            this->isRunning = false;
        case Display::Event::A:
        case Display::Event::B:
        case Display::Event::C:
        case Display::Event::D:
        case Display::Event::E:
        case Display::Event::F:
        case Display::Event::G:
        case Display::Event::H:
        case Display::Event::I:
        case Display::Event::J:
        case Display::Event::K:
        case Display::Event::L:
        case Display::Event::M:
        case Display::Event::N:
        case Display::Event::O:
        case Display::Event::P:
        case Display::Event::Q:
        case Display::Event::R:
        case Display::Event::S:
        case Display::Event::T:
        case Display::Event::U:
        case Display::Event::V:
        case Display::Event::W:
        case Display::Event::X:
        case Display::Event::Y:
        case Display::Event::Z:
        case Display::Event::Num1:
        case Display::Event::Num2:
        case Display::Event::Num3:
        case Display::Event::Num4:
        case Display::Event::Num5:
        case Display::Event::Num6:
        case Display::Event::Num7:
        case Display::Event::Num8:
        case Display::Event::Num9:
        case Display::Event::Backspace:
        case Display::Event::Space:
            this->handleUsernameEvents(event);
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
