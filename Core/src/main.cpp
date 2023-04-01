/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include <string>

int check_env()
{
    const char* display = std::getenv("DISPLAY");

    if (display != nullptr)
        return SUCCESS;
    std::cerr << "Error: DISPLAY is not set" << std::endl;
    return ERROR;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./arcade [lib]" << std::endl;
        return ERROR;
    }
    if (check_env() == ERROR)
        return ERROR;
    return arcade(argv[1]);
}
