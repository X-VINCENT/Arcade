/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** Arcade
*/

#pragma once
#include <vector>
#include <map>
#include <string>
#include "DLLoader.hpp"
#include "IFactory.hpp"
#include "IGameModule.hpp"
#include "Menu.hpp"

namespace Core {
    enum HandlerState {
        MENU,
        GAME
    };
    class Handler {
        public:
            Handler(std::string const &displayLibPath);
            ~Handler();
            void createFactory();
            void createGame();
            void loop();
            void handleGameEvents();
            void handleMenuEvents();

        protected:
        private:
            std::vector<std::map <std::string, std::string>> games;
            std::vector<std::map <std::string, std::string>> graphics;
            std::vector <std::string> gameNames;
            std::vector <std::string> graphicNames;
            int selectedGame;
            int selectedGraphic;
            std::string gamePath;
            DLLoader displayLoader;
            DLLoader gameLoader;
            std::unique_ptr<Display::IFactory> factory;
            std::unique_ptr<Game::IGameModule> game;
            bool isRunning;
            std::unique_ptr<Core::Menu> menu;
            enum HandlerState current_state;
    };
}
