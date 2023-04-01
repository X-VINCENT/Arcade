/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLClock
*/

#pragma once
#include "IClock.hpp"
#include <SFML/Graphics.hpp>

namespace Display {
    class SFMLClock : public IClock {
        public:
            SFMLClock();
            ~SFMLClock() override;
            int getElapsedTime() override;
            void restart() override;

        private:
            sf::Clock clock;
    };
};
