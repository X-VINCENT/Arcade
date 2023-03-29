/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2Event.hpp
*/

#pragma once
#include "IEvent.hpp"

namespace Display {
    class SDLEvent : public IEvent {
        public:
            ~SDLEvent();
            Display::KeyType getType() override;
            void setType(Display::KeyType &type) override;

        protected:
        private:
            Display::KeyType type;
    };
}