/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include <string>

int check_env(char **env)
{
    if (!env) {
        std::cerr << "Error: No environment found." << std::endl;
        return ERROR;
    }
    for (int i = 0; env[i] != NULL; i += 1) {
        if (env[i] == "DISPLAY")
            return SUCCESS;
    }
    std::cerr << "Error: No display found." << std::endl;
    return ERROR;
}

int main(int argc, char **argv, char **env)
{
    if (argc != 2)
        return ERROR;
    if (check_env(env) == ERROR)
        return ERROR;
    return arcade(argv[1]);
}
