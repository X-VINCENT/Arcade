/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** DLLoader.hpp
*/

#pragma once
#include <string>
#include <dlfcn.h>
#include <memory>
#include <functional>

namespace Core {
    class DLLoader {
        public:
            DLLoader() = delete;
            DLLoader(std::string const &path);
            ~DLLoader();

            template<class T>
            T getInstance(const std::string &path) const
            {
                void *gptr = dlsym(this->_handle, path.c_str());

                if (gptr == nullptr)
                    return T();
                return std::move(reinterpret_cast<T>(gptr));
            }

            void changeLib(std::string const &path);

        protected:
            void *_handle;
    };
}
