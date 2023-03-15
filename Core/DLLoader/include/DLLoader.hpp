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

class DLLoader {
	public:
        DLLoader() = delete;
        explicit DLLoader(std::string const &path);
        ~DLLoader();
        static int test(){return 1;};
        template <class T>
        T *getInstance(std::string const &path);

	protected:
	private:
        void *_handle;
};
