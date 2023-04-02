/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Menu.hpp
*/

#pragma once
#include "IFactory.hpp"
#include "Event.hpp"
#include <vector>
#include <string>

namespace Core {
    class Menu {
        public:
            Menu(
                Display::IFactory &factory,
                std::vector<std::string> const &games,
                std::vector<std::string> const &graphics
            );
            ~Menu();
            void setSelectedGame(int selectedGame);
            void setSelectedGraphic(int selectedGraphic);
            Display::Event getEvent() const;
            void render();
            void stop();

        private:
            std::unique_ptr<Display::IWindow> window;
            std::unique_ptr<Display::IClock> renderClock;
            std::unique_ptr<Display::IFont> arialFont;
            std::unique_ptr<Display::IText> title;
            std::unique_ptr<Display::IText> gamesTitle;
            std::unique_ptr<Display::IText> graphicsTitle;
            std::vector<std::unique_ptr<Display::IText>> gamesKeys;
            std::vector<std::unique_ptr<Display::IText>> gamesTexts;
            std::vector<std::unique_ptr<Display::IText>> graphicsKeys;
            std::vector<std::unique_ptr<Display::IText>> graphicsTexts;
            std::unique_ptr<Display::IText> keyInfos;
    };
}
