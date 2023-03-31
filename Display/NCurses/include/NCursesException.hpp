/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** NCursesException
*/

#pragma once
#include <exception>
#include <string>

namespace Display {
    class NCursesException : public std::exception {
        public:
            NCursesException(const std::string &message);
            ~NCursesException() noexcept override;
            const char* what() const noexcept override;

        private:
            std::string message;
    };
}
