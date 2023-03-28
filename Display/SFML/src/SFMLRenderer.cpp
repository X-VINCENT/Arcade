/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-max.peixoto
** File description:
** SFMLRenderer
*/

#include "SFMLRenderer.hpp"
#include <memory>

Display::SFMLRenderer::~SFMLRenderer()
{
}

void Display::SFMLRenderer::create(std::unique_ptr<Display::IWindow> &window)
{
    (void)window;
}

std::unique_ptr<Display::IRenderer> Display::SFMLRenderer::clone() const
{
    return std::make_unique<Display::SFMLRenderer>(*this);
}

extern "C" std::unique_ptr<Display::IRenderer> createRenderer()
{
    return std::make_unique<Display::SFMLRenderer>();
}
