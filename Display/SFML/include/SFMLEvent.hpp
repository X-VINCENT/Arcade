/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLEvent
*/

#pragma once
#include "IEvent.hpp"

namespace Display {
    class SFMLEvent : public IEvent {
        public:
            ~SFMLEvent();
            Display::KeyType &getType() override;
            void setType(Display::KeyType type) override;

        protected:
        private:
            Display::KeyType type;
    };
};
