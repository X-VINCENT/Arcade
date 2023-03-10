/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Snake.hpp
*/

#pragma once
#include "IGameModule.hpp"
#include <iostream>

class Snake : public IGameModule {
	public:
		Snake();
		~Snake();
        void init() override;
        void stop() override;
        const std::string &getName() const;

	protected:
	private:
        std::string _name;
};
