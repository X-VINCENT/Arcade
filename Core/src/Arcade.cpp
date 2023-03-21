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

    /* std::string const &createTextureFn = "createTexture";
    using textureFnPtr = std::unique_ptr<Display::ITexture> (*)();
    textureFnPtr createTexture = libLoader.template getInstance<textureFnPtr>(createTextureFn);
    std::unique_ptr<Display::ITexture> texture = createTexture();


    texture->load('#', "assets/block.png"); */
    window->clear();
    window->draw();
    window->display();
    window->close();
    return SUCCESS;
}
