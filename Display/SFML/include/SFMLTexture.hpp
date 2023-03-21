/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SFMLTexture
*/

#include "ITexture.hpp"
#include "SFML/Graphics.hpp"

#ifndef ARCADE_SFMLTEXTURE_HPP
#define ARCADE_SFMLTEXTURE_HPP

namespace Display {
    class SFMLTexture : public ITexture {
    public:
        SFMLTexture();
        ~SFMLTexture();
        ITexture &load(char c, const std::string fpath) override;

    private:
        std::unique_ptr<sf::Texture> texture;
    };
}

#endif //ARCADE_SFMLTEXTURE_HPP
