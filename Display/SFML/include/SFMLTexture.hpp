/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#pragma once

#include "ITexture.hpp"
#include "SFML/Graphics.hpp"

namespace Display {
    class SFMLTexture : public ITexture {
        public:
            SFMLTexture(std::string const &texturePath);
            ~SFMLTexture() override;
            sf::Texture &getSFTexture();

        private:
            sf::Texture texture;
    };
}
