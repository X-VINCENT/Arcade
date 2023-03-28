/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include <fcntl.h>
#include <iostream>

int arcade(std::string const &displayLibPath)
{
    DLLoader displayLoader(displayLibPath);
    DLLoader gameLoader("lib/libsnake.so");

    std::string const &createWindowFn = "createWindow";
    std::string const &createTextureFn = "createTexture";
    std::string const &createSpriteFn = "createSprite";
    std::string const &createGameFn = "createGame";

    using windowFnPtr = std::unique_ptr<Display::IWindow> (*)();
    using textureFnPtr = std::unique_ptr<Display::ITexture> (*)();
    using spriteFnPtr = std::unique_ptr<Display::ISprite> (*)();
    using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)();

    windowFnPtr createWindow = displayLoader.template getInstance<windowFnPtr>(createWindowFn);
    textureFnPtr createTexture = displayLoader.template getInstance<textureFnPtr>(createTextureFn);
    spriteFnPtr createSprite = displayLoader.template getInstance<spriteFnPtr>(createSpriteFn);
    gameFnPtr createGame = gameLoader.template getInstance<gameFnPtr>(createGameFn);

    std::unique_ptr<Display::IWindow> window = createWindow();
    std::unique_ptr<Display::ITexture> texture = createTexture();
    std::unique_ptr<Display::ISprite> sprite = createSprite();

    window->create("Arcade", 60, 100, 100);
    texture->load('#', "assets/snake/body.png");
    sprite->create(std::move(texture), Display::IIntRect{0, 0, 10, 10}, Display::IVector2f{50, 50});
    while (window->isOpen()) {
        Display::KeyType key = window->getEvent()->getType();
        switch (key) {
            case Display::KeyType::Q:
                sprite->move(Display::IVector2f{-10, 0});
                break;
            case Display::KeyType::D:
                sprite->move(Display::IVector2f{10, 0});
                break;
            case Display::KeyType::Z:
                sprite->move(Display::IVector2f{0, -10});
                break;
            case Display::KeyType::S:
                sprite->move(Display::IVector2f{0, 10});
                break;
            case Display::KeyType::Enter:
                window->close();
                break;
            default:
                break;
        }
        window->clear();
        window->draw(sprite);
        window->display();
    }
    return SUCCESS;
}
