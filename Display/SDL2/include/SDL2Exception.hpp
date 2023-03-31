/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Exception
*/

#pragma once
#include <exception>
#include <string>

namespace Display {
    class SDL2Exception : public std::exception {
        public:
            SDL2Exception(const std::string &message);
            ~SDL2Exception() noexcept override;
            const char* what() const noexcept override;

        private:
            std::string message;
    };
}
