/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCurses.hpp
*/

#pragma once
#include <string>
#include <dlfcn.h>
#include <functional>

template <typename T>
class DLLoader {
	public:
        explicit DLLoader(std::string const &path);
        ~DLLoader();
        std::function<T> getInstance(std::string const &path);

	protected:
	private:
        void *_handle;
        std::function<T> _instance;
};
