/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"

#include <fcntl.h>

int arcade()
{
    std::string libName = "./libgames.so";
    void *test = dlopen(libName.c_str(), RTLD_LAZY);
    auto test2 = reinterpret_cast<void *()>(dlsym(test, "getName"));
    /*
    DLLoader snake(libName);

    auto test = snake.getInstance<const std::string()>("getName");*/
    test2();
    return SUCCESS;
}
