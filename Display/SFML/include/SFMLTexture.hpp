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
        SFMLTexture();
        ~SFMLTexture();
        void load(char c, std::string const &fpath) override;

    private:
        std::unique_ptr<sf::Texture> texture;
    };
}
