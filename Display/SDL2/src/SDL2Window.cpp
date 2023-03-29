/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Window
*/

#include "SDL2Window.hpp"
#include "SDL2Texture.hpp"
#include "SDL2Sprite.hpp"
#include <iostream>

Display::SDL2Window::SDL2Window(
    std::string const &title,
    int framerateLimit,
    int width,
    int height
)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        exit(84);
    }
    this->window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width * 10,
        height * 10,
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        exit(84);
    }
}

Display::SDL2Window::~SDL2Window()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

Display::Event Display::SDL2Window::getEvent()
{
    SDL_Event SDL_event;

    SDL_PollEvent(&SDL_event);
    switch (SDL_event.key.keysym.sym) {
        case SDLK_a:
            return Display::Event::A;
        case SDLK_b:
            return Display::Event::B;
        case SDLK_c:
            return Display::Event::C;
        case SDLK_d:
            return Display::Event::D;
        case SDLK_e:
            return Display::Event::E;
        case SDLK_f:
            return Display::Event::F;
        case SDLK_g:
            return Display::Event::G;
        case SDLK_h:
            return Display::Event::H;
        case SDLK_i:
            return Display::Event::I;
        case SDLK_j:
            return Display::Event::J;
        case SDLK_k:
            return Display::Event::K;
        case SDLK_l:
            return Display::Event::L;
        case SDLK_m:
            return Display::Event::M;
        case SDLK_n:
            return Display::Event::N;
        case SDLK_o:
            return Display::Event::O;
        case SDLK_p:
            return Display::Event::P;
        case SDLK_q:
            return Display::Event::Q;
        case SDLK_r:
            return Display::Event::R;
        case SDLK_s:
            return Display::Event::S;
        case SDLK_t:
            return Display::Event::T;
        case SDLK_u:
            return Display::Event::U;
        case SDLK_v:
            return Display::Event::V;
        case SDLK_w:
            return Display::Event::W;
        case SDLK_x:
            return Display::Event::X;
        case SDLK_y:
            return Display::Event::Y;
        case SDLK_z:
            return Display::Event::Z;
        case SDLK_0:
            return Display::Event::Num0;
        case SDLK_1:
            return Display::Event::Num1;
        case SDLK_2:
            return Display::Event::Num2;
        case SDLK_3:
            return Display::Event::Num3;
        case SDLK_4:
            return Display::Event::Num4;
        case SDLK_5:
            return Display::Event::Num5;
        case SDLK_6:
            return Display::Event::Num6;
        case SDLK_7:
            return Display::Event::Num7;
        case SDLK_8:
            return Display::Event::Num8;
        case SDLK_9:
            return Display::Event::Num9;
        case SDLK_LEFT:
            return Display::Event::Left;
        case SDLK_RIGHT:
            return Display::Event::Right;
        case SDLK_UP:
            return Display::Event::Up;
        case SDLK_DOWN:
            return Display::Event::Down;
        case SDLK_ESCAPE:
            return Display::Event::Escape;
        case SDLK_RETURN:
            return Display::Event::Enter;
        case SDLK_SPACE:
            return Display::Event::Space;
        default:
            break;
    }

    switch (SDL_event.type) {
        case SDL_QUIT:
            return Display::Event::Close;
        default:
            break;
    }

    return Display::Event::Unknown;
}

void Display::SDL2Window::setTitle(const std::string &title)
{
    SDL_SetWindowTitle(this->window, title.c_str());
}

bool Display::SDL2Window::isOpen()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return false;
    }
    return true;
}

void Display::SDL2Window::clear()
{
    SDL_RenderClear(this->renderer);
}

void Display::SDL2Window::display()
{
    SDL_RenderPresent(this->renderer);
}

void Display::SDL2Window::draw(Display::ISprite &sprite)
{
    Display::SDL2Sprite &sdlSprite = dynamic_cast<Display::SDL2Sprite &>(sprite);

    SDL_Texture *texture = &sdlSprite.getSDLSprite();

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    SDL_Rect texr;
    texr.x = 1000/2; texr.y = 1000/2; texr.w = w; texr.h = h;

    SDL_RenderCopy(this->renderer, texture, nullptr, &texr);
}

void Display::SDL2Window::close()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

SDL_Window *Display::SDL2Window::getSDL2Window() const
{
    return this->window;
}

SDL_Renderer *Display::SDL2Window::getRenderer() const
{
    return this->renderer;
}
