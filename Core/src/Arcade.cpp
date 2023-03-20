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
    const char *libName = "./libgames.so";
    DLLoader libloader(displayLibPath);
    const std::string &str = "createWindow";

    using fptr = std::unique_ptr<Display::IDisplayModule> (*)();
    fptr createWindow = libloader.template getInstance<fptr>(str);
    std::unique_ptr<Display::IDisplayModule> window = createWindow();
    window->create();
    sleep(10);
    return SUCCESS;
}
