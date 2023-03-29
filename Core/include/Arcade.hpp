/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** Arcade
*/

#pragma once

// C++ includes

// Project includes
#include "DLLoader.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "IEvent.hpp"
#include "IException.hpp"
#include "IntRect.hpp"
#include "ISprite.hpp"
#include "ITexture.hpp"
#include "Vector2f.hpp"
#include "IWindow.hpp"
#include "IRenderer.hpp"

// Macros
#define SUCCESS 0
#define ERROR 84

// Prototypes
int arcade(std::string const &displayLibPath);
