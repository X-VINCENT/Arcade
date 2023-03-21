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
            SFMLTexture() = default;
            ~SFMLTexture();
            void load(char c, std::string const &fpath) override;
            sf::Texture getSFMLTexture() const;

        private:
            sf::Texture texture;
    };
}
