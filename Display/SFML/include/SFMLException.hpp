/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLException
*/

#pragma once
#include <exception>
#include <string>

namespace Display {
    class SFMLException : public std::exception {
        public:
            SFMLException(const std::string &message);
            ~SFMLException() noexcept override;
            const char* what() const noexcept override;

        private:
            std::string message;
    };
}
