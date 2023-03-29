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
    class NCurses : public IDisplayModule {
        public:
            NCurses();
            ~NCurses();
            void update() override;
            void destroy() override;

        protected:
        private:
            std::string _name;
    };
}
