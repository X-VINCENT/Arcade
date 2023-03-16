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
/*    void *handle = dlopen(libName, RTLD_LAZY);
    if (handle == nullptr)
        return 83;
    void *gptr = dlsym(handle, "createGame") ;
    if (gptr == nullptr)
        return  84;
    using fptr = std::unique_ptr<Game::IGameModule> (*)();
    fptr my_fptr = reinterpret_cast<fptr>(gptr);*/

    DLLoader libloader("./libdisplays.so");
    const std::string &str = "createWindow";

    using fptr = std::unique_ptr<Display::IDisplayModule> (*)();
    fptr lib = libloader.template getInstance<fptr>(str);
    std::unique_ptr<Display::IDisplayModule> game = lib();
    game->create();
    return SUCCESS;
}
