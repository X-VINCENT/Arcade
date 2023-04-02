/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "Menu.hpp"
#include <vector>
#include <map>

int arcade(std::string const &displayLibPath)
{
    Core::DLLoader displayLoader(displayLibPath);
    Core::DLLoader gameLoader("lib/arcade_snake.so");

    std::string const &createFactoryFn = "createFactory";
    using factoryFnPtr = std::unique_ptr<Display::IFactory> (*)();
    factoryFnPtr createFactory = displayLoader.template getInstance<factoryFnPtr>(createFactoryFn);
    std::unique_ptr<Display::IFactory> factory = createFactory();

    std::string const &createGameFn = "createGame";
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
    gameFnPtr createGame = nullptr;

    std::vector<std::map <std::string, std::string>> games = {
        {
            {"name", "Snake"},
            {"path", "lib/arcade_snake.so"}
        },
        {
            {"name", "Centipede"},
            {"path", "lib/arcade_centipede.so"}
        }
    };

    std::vector<std::map <std::string, std::string>> graphics = {
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

    std::vector <std::string> gameNames;
    std::vector <std::string> graphicNames;

    for (auto &game : games) {
        gameNames.push_back(game["name"]);
    }

    for (auto &graphic : graphics) {
        graphicNames.push_back(graphic["name"]);
    }

    Core::Menu menu(*factory, gameNames, graphicNames);
    bool isRunning = true;

    int selectedGame = 0;
    int selectedGraphic = 0;

    std::string gamePath = games[selectedGame]["path"];
    std::unique_ptr<Game::IGameModule> game = nullptr;

    while (isRunning) {
        // When we change lib, there is a segfault HERE
        Display::Event event = menu.getEvent();

        switch (event) {
            case Display::Event::Close:
            case Display::Event::Escape:
                isRunning = false;
                break;
            case Display::Event::Left:
                selectedGame += 1;
                break;
            case Display::Event::Right:
                selectedGame -= 1;
                break;
            case Display::Event::Up:
                selectedGraphic -= 1;
                break;
            case Display::Event::Down:
                selectedGraphic += 1;
                break;
            case Display::Event::Enter:
                std::cout << "Enter" << std::endl;
                menu.stop();
                menu.~Menu();
                gamePath = games[selectedGame]["path"];
                gameLoader.changeLib(gamePath);
                createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);
                game = createGame(*factory);
                game->run(*factory);
                break;
            case Display::Event::Space:
                displayLoader.changeLib(graphics[selectedGraphic]["path"]);
                createFactory = displayLoader.template getInstance<factoryFnPtr>(createFactoryFn);
                factory = createFactory();
                menu.updateFactory(*factory);
                break;
            default:
                break;
        }
        if (selectedGame < 0)
            selectedGame = games.size() - 1;
        if (selectedGame >= games.size())
            selectedGame = 0;
        if (selectedGraphic < 0)
            selectedGraphic = graphics.size() - 1;
        if (selectedGraphic >= graphics.size())
            selectedGraphic = 0;
        menu.setSelectedGame(selectedGame);
        menu.setSelectedGraphic(selectedGraphic);
        menu.render();
    }
    menu.stop();

    /* std::string const &createGameFn = "createGame";
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
    gameFnPtr createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);
    std::unique_ptr<Game::IGameModule> game = createGame(*factory);

    game->run(*factory); */
    return SUCCESS;
}
