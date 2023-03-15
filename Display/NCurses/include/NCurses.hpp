/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCurses.hpp
*/

#pragma once
#include "IDisplayModule.hpp"

class NCurses : public IDisplayModule {
	public:
		NCurses();
		~NCurses() override;
        void init();
        void stop();
        const std::string &getName() const;

	protected:
	private:
        std::string _name;
};
