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
		~Snake() override;
        void init() override;
        void stop() override;
        [[nodiscard]] const std::string &getName() const override;
        [[nodiscard]] const std::vector<IGameObject> &getObjects() const override;

	protected:
	private:
        std::string _name;
        std::vector<IGameObject> _objects;
};
