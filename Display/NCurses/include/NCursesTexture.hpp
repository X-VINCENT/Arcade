/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesTexture
*/

#pragma once
#include "ITexture.hpp"

namespace Display {
    class NCursesTexture : public ITexture {
        public:
            NCursesTexture(char c);
            ~NCursesTexture();
            char getChar() const;

        private:
            char c;
    };
};
