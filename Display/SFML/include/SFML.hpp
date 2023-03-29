/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCurses.hpp
*/

#pragma once
#include "IDisplayModule.hpp"
#include <memory>
#include <SFML/Graphics/Sprite.hpp>

namespace Display {
    class SFML : public IDisplayModule {
        public:
            SFML();
            ~SFML();
            void update() override;
            void destroy() override;

        protected:
        private:
            std::string _name;
    };
}
