/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** IClock
*/

#pragma once
#include <string>

namespace Display {
    class IClock {
        public:
            virtual ~IClock() = default;
            virtual int getElapsedTime() = 0;
            virtual void restart() = 0;
    };
};
