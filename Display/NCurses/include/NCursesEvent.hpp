/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** NCursesEvent
*/

#pragma once
#include "IEvent.hpp"

namespace Display {
    class NCursesEvent : public IEvent {
        public:
            NCursesEvent() = default;
            Display::KeyType getType() override;
            void setType(Display::KeyType type) override;

        protected:
        private:
            Display::KeyType type;
    };
};
