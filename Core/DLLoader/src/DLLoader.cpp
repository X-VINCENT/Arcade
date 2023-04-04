/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"
#include <exception>
#include <iostream>
#include <sstream>

Core::DLLoader::DLLoader(std::string const &path)
    : _handle(nullptr)
{
    FILE *file = fopen(path.c_str(), "r");
    try {
        if (file == nullptr)
            throw std::runtime_error("Failed to load library: " + path + " does not exist");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    fclose(file);

    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    try {
        if (this->_handle == nullptr)
            throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
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

    FILE *file = fopen(path.c_str(), "r");
    try {
        if (file == nullptr)
            throw std::runtime_error("Failed to load library: " + path + " does not exist");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    fclose(file);

    this->_handle = dlopen(path.c_str(), RTLD_LAZY);
    try {
        if (this->_handle == nullptr)
            throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}
