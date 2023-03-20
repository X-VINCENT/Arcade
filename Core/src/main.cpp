/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return ERROR;
    return arcade(argv[1]);
}
