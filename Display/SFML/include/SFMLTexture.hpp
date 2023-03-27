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
            ~SFMLTexture() override;
            void load(char c, std::string const &fpath) override;
            std::unique_ptr<ITexture> clone() const override;
            sf::Texture &getSFMLTexture();

        private:
            sf::Texture texture;
    };
}
