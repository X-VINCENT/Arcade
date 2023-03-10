/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"

template<typename T>
DLLoader<T>::DLLoader(std::string const &path)
{
    _handle = dlopen(path.c_str(), RTLD_LAZY);
}

template<typename T>
DLLoader<T>::~DLLoader()
{
    dlclose(_handle);
}

template<typename T>
std::function<T> DLLoader<T>::getInstance(std::string const &path)
{
    _instance = reinterpret_cast<std::function<T>>(dlsym(_handle, path.c_str()));
    return _instance;
}
