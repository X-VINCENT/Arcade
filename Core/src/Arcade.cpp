/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"

int arcade(std::string const &displayLibPath)
{
    DLLoader displayLoader(displayLibPath);
    DLLoader gameLoader("lib/libsnake.so");

    std::string const &createFactoryFn = "createFactory";
    using factoryFnPtr = std::unique_ptr<Display::IFactory> (*)();
    factoryFnPtr createFactory = displayLoader.template getInstance<factoryFnPtr>(createFactoryFn);
    std::unique_ptr<Display::IFactory> factory = createFactory();

    std::string const &createGameFn = "createGame";
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
    gameFnPtr createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);
    std::unique_ptr<Game::IGameModule> game = createGame(*factory);

    game->run(*factory);
    return SUCCESS;
}
