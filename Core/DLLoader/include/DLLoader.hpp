/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCurses.hpp
*/

#pragma once

#include <string>
#include <dlfcn.h>
#include <memory>
#include <functional>

class DLLoader {
public:
    DLLoader() = delete;

    explicit DLLoader(std::string const &path);

    ~DLLoader();

    static int test()
    { return 1; };

    template<class T>
    T getInstance(const std::string &path) const
    {
        void *gptr = dlsym(this->_handle, path.c_str());
        if (gptr == nullptr)
            return T();
        return std::move(reinterpret_cast<T>(gptr));
    }

    void *_handle;
protected:
};
