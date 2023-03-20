/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "NCurses.hpp"
#include <fcntl.h>

int arcade(std::string const &displayLibPath)
{
    const char *libName = displayLibPath.c_str();
    DLLoader libloader(displayLibPath);
    const std::string &str = "createWindow";

    using fptr = std::unique_ptr<Display::IWindow> (*)();
    fptr createWindow = libloader.template getInstance<fptr>(str);
    std::unique_ptr<Display::IWindow> window = createWindow();
    window->create("Arcade", 60, 100, 100);
    window->clear();
    window->draw();
    window->display();
    window->close();
    return SUCCESS;
}
