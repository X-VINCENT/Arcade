/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "Handler.hpp"

int arcade(std::string const &displayLibPath)
{
    Core::Handler handler(displayLibPath);

    handler.loop();

    /* std::string const &createGameFn = "createGame";
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
    gameFnPtr createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);
    std::unique_ptr<Game::IGameModule> game = createGame(*factory);

    game->run(*factory); */
    return SUCCESS;
}
