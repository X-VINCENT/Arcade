/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Printable.hpp
*/

#pragma once
#include "IGameModule.hpp"

class Printable {
    public:
        enum Colors {
            BLACK,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE
        };
        Printable(char c, Colors color, std::string path);
        ~Printable() = default;
        const char &getC() const;
        void setC(const char &newC);
        Colors getColor() const;
        void setColor(Colors newColor);
        const std::string &getPath() const;
        void setPath(const std::string &newPath);

    protected:
    private:
        char c;
        Colors color;
        std::string path;
};
