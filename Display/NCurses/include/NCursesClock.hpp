/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesClock
*/

#pragma once
#include "IClock.hpp"
#include <ncurses.h>

namespace Display {
    class NCursesClock : public IClock {
        public:
            NCursesClock();
            ~NCursesClock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            clock_t startClock;
    };
};
