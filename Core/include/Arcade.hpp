/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** Arcade
*/

#pragma once

#include "IFactory.hpp"
#include "IGameModule.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

// Project includes
#include "DLLoader.hpp"

// Macros
#define SUCCESS 0
#define ERROR 84

// Prototypes
int arcade(std::string const &displayLibPath);
