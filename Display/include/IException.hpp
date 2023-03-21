/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IException
*/

#pragma once
#include <exception>

namespace Display {
    class IException : public std::exception {
        public:
            virtual ~IException() noexcept;
            virtual const char* what() const noexcept = 0;
    };
}
