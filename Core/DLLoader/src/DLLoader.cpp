/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"

Core::DLLoader::DLLoader(std::string const &path)
{
    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    if (this->_handle == nullptr) {
        printf(dlerror());
        exit(84);
    }
}

Core::DLLoader::~DLLoader()
{
    dlclose(this->_handle);
}

void Core::DLLoader::changeLib(std::string const &path)
{
    if (this->_handle != nullptr)
        dlclose(this->_handle);
    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    if (this->_handle == nullptr) {
        printf(dlerror());
        exit(84);
    }
}
