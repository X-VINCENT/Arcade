/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SDL2Clock
*/

#pragma once
#include "IClock.hpp"
#include <SDL2/SDL.h>

namespace Display {
    class SDL2Clock : public IClock {
        public:
            SDL2Clock();
            ~SDL2Clock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            Uint32 clock;
    };
};
