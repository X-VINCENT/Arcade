/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"

class Snake : public IGameModule {
	public:
		Snake();
		~Snake();
        void init();
        void stop();
        const std::string &getName() const;

	protected:
	private:
        std::string _name;
};
