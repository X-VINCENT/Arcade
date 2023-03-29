/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

int arcade(std::string const &displayLibPath)
{
    DLLoader displayLoader(displayLibPath);
    DLLoader gameLoader("lib/libsnake.so");

    std::string const &createWindowFn = "createWindow";
    std::string const &createTextureFn = "createTexture";
    std::string const &createSpriteFn = "createSprite";
    std::string const &createGameFn = "createGame";
    std::string const &createRendererFn = "createRenderer";

    using windowFnPtr = std::unique_ptr<Display::IWindow> (*)();
    using textureFnPtr = std::unique_ptr<Display::ITexture> (*)();
    using spriteFnPtr = std::unique_ptr<Display::ISprite> (*)();
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)();
    using rendererFnPtr = std::unique_ptr<Display::IRenderer> (*)();

    windowFnPtr createWindow = displayLoader.template getInstance<windowFnPtr>(createWindowFn);
    textureFnPtr createTexture = displayLoader.template getInstance<textureFnPtr>(createTextureFn);
    spriteFnPtr createSprite = displayLoader.template getInstance<spriteFnPtr>(createSpriteFn);
    gameFnPtr createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);
    rendererFnPtr createRenderer = displayLoader.template getInstance<rendererFnPtr>(createRendererFn);

    std::unique_ptr<Game::IGameModule> game = createGame();

    game->setFunctions(createWindow, createTexture, createSprite, createRenderer);
    game->init();
    while (1) {
        game->update();
        usleep(100000);
    }
    game->stop();
    return SUCCESS;
}
