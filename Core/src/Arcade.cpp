/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "NCurses.hpp"

#include <fcntl.h>

int arcade()
{
    const char *libName = "./libgames.so";

    DLLoader libloader("./libdisplays.so");
    const std::string &str = "createWindow";

    using fptr = std::unique_ptr<Display::IDisplayModule> (*)();
    fptr lib = libloader.getInstance<fptr>(str);
    std::unique_ptr<Display::IDisplayModule> game = lib();
    game->create();
    return SUCCESS;
}
