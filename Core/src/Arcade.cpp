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
    std::cout << "Graphic Library: " << displayLibPath << std::endl;
    DLLoader libLoader(displayLibPath);
    std::cout << "Graphic Library Loaded" << std::endl;

    std::string const &createWindowFn = "createWindow";
    using windowFnPtr = std::unique_ptr<Display::IWindow> (*)();
    windowFnPtr createWindow = libLoader.template getInstance<windowFnPtr>(createWindowFn);
    std::unique_ptr<Display::IWindow> window = createWindow();

    std::string const &createTextureFn = "createTexture";
    using textureFnPtr = std::unique_ptr<Display::ITexture> (*)();
    textureFnPtr createTexture = libLoader.template getInstance<textureFnPtr>(createTextureFn);
    std::unique_ptr<Display::ITexture> texture = createTexture();

    std::string const &createSpriteFn = "createSprite";
    using spriteFnPtr = std::unique_ptr<Display::ISprite> (*)();
    spriteFnPtr createSprite = libLoader.template getInstance<spriteFnPtr>(createSpriteFn);
    std::unique_ptr<Display::ISprite> sprite = createSprite();


    Display::IIntRect rect{(Display::IIntRect){0, 0, 10, 10}};
    Display::IVector2f vect{(Display::IVector2f){10, 10}};
    texture->load('#', "assets/block.png");;
    sprite->create(std::move(texture), rect, vect);
    window->create("Arcade", 60, 100, 100);
    window->clear();
    window->draw();
    window->display();
    window->close();
    return SUCCESS;
}
