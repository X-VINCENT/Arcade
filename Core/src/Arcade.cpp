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

    std::string const &createIntRectFn = "createIntRect";
    using intRectFnPtr = std::unique_ptr<Display::IIntRect> (*)();
    intRectFnPtr createIntRect = libLoader.template getInstance<intRectFnPtr>(createIntRectFn);
    std::unique_ptr<Display::IIntRect> intRect = createIntRect();

    std::string const &createVector2fFn = "createVector2f";
    using vector2fFnPtr = std::unique_ptr<Display::IVector2f> (*)();
    vector2fFnPtr createVector2f = libLoader.template getInstance<vector2fFnPtr>(createVector2fFn);
    std::unique_ptr<Display::IVector2f> vector2f = createVector2f();


    texture->load('#', "assets/block.png");
    intRect->create(0, 0, 10, 10);
    vector2f->create(0, 0);
    // sprite->create(texture, intRect, vector2f); => SEGFAULT with SFML
    window->create("Arcade", 60, 100, 100);
    window->clear();
    window->draw();
    window->display();
    window->close();
    return SUCCESS;
}
