/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2.hpp
*/

#pragma once
#include "IDisplayModule.hpp"

namespace Display {
    class SDL2 : public IDisplayModule {
    public:
        SDL2();
        ~SDL2() override;
        void update() override;
        void destroy() override;

    protected:
    private:
        std::string _name;
    };
}
