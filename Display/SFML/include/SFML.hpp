/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCurses.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
#include <memory>

namespace Display {
    class SFML : public IDisplayModule {
        public:
            SFML();
            ~SFML() override;
            void create() override;
            void draw() override;
            void destroy() override;

        protected:
        private:
            std::string _name;
            sf::Sprite **sprites;
    };
}
