/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SDL2Window
*/

#include "SDL2Window.hpp"
#include "SDL2Event.hpp"
#include "SDL2Texture.hpp"
#include <map>

using KeyToEventTypeMap = std::map<SDL_Keycode, Display::KeyType>;
static const KeyToEventTypeMap KeyToEventType = {
    {SDLK_a, Display::KeyType::A},
    {SDLK_b, Display::KeyType::B},
    {SDLK_c, Display::KeyType::C},
    {SDLK_d, Display::KeyType::D},
    {SDLK_e, Display::KeyType::E},
    {SDLK_f, Display::KeyType::F},
    {SDLK_g, Display::KeyType::G},
    {SDLK_h, Display::KeyType::H},
    {SDLK_i, Display::KeyType::I},
    {SDLK_j, Display::KeyType::J},
    {SDLK_k, Display::KeyType::K},
    {SDLK_l, Display::KeyType::L},
    {SDLK_m, Display::KeyType::M},
    {SDLK_n, Display::KeyType::N},
    {SDLK_o, Display::KeyType::O},
    {SDLK_p, Display::KeyType::P},
    {SDLK_q, Display::KeyType::Q},
    {SDLK_r, Display::KeyType::R},
    {SDLK_s, Display::KeyType::S},
    {SDLK_t, Display::KeyType::T},
    {SDLK_u, Display::KeyType::U},
    {SDLK_v, Display::KeyType::V},
    {SDLK_w, Display::KeyType::W},
    {SDLK_x, Display::KeyType::X},
    {SDLK_y, Display::KeyType::Y},
    {SDLK_z, Display::KeyType::Z},
    {SDLK_0, Display::KeyType::Num0},
    {SDLK_1, Display::KeyType::Num1},
    {SDLK_2, Display::KeyType::Num2},
    {SDLK_3, Display::KeyType::Num3},
    {SDLK_4, Display::KeyType::Num4},
    {SDLK_5, Display::KeyType::Num5},
    {SDLK_6, Display::KeyType::Num6},
    {SDLK_7, Display::KeyType::Num7},
    {SDLK_8, Display::KeyType::Num8},
    {SDLK_9, Display::KeyType::Num9},
    {SDLK_ESCAPE, Display::KeyType::Escape},
    {SDLK_LCTRL, Display::KeyType::LControl},
    {SDLK_LSHIFT, Display::KeyType::LShift},
    {SDLK_LALT, Display::KeyType::LAlt},
    {SDLK_LGUI, Display::KeyType::LSystem},
    {SDLK_RCTRL, Display::KeyType::RControl},
    {SDLK_RSHIFT, Display::KeyType::RShift},
    {SDLK_RALT, Display::KeyType::RAlt},
    {SDLK_RGUI, Display::KeyType::RSystem},
    {SDLK_MENU, Display::KeyType::Menu},
    {SDLK_LEFTBRACKET, Display::KeyType::LBracket},
    {SDLK_RIGHTBRACKET, Display::KeyType::RBracket},
    {SDLK_SEMICOLON, Display::KeyType::SemiColon},
    {SDLK_COMMA, Display::KeyType::Comma},
    {SDLK_PERIOD, Display::KeyType::Period},
    {SDLK_QUOTE, Display::KeyType::Quote},
    {SDLK_SLASH, Display::KeyType::Slash},
    {SDLK_BACKSLASH, Display::KeyType::BackSlash},
    {SDLK_BACKQUOTE, Display::KeyType::Tilde},
    {SDLK_EQUALS, Display::KeyType::Equal},
    {SDLK_MINUS, Display::KeyType::Dash},
    {SDLK_SPACE, Display::KeyType::Space},
    {SDLK_RETURN, Display::KeyType::Return},
    {SDLK_BACKSPACE, Display::KeyType::BackSpace},
    {SDLK_TAB, Display::KeyType::Tab},
    {SDLK_PAGEUP, Display::KeyType::PageUp},
    {SDLK_PAGEDOWN, Display::KeyType::PageDown},
    {SDLK_END, Display::KeyType::End},
    {SDLK_HOME, Display::KeyType::Home},
    {SDLK_INSERT, Display::KeyType::Insert},
    {SDLK_DELETE, Display::KeyType::Delete},
    {SDLK_KP_PLUS, Display::KeyType::Add},
    {SDLK_KP_MINUS, Display::KeyType::Subtract},
    {SDLK_KP_MULTIPLY, Display::KeyType::Multiply},
    {SDLK_KP_DIVIDE, Display::KeyType::Divide},
    {SDLK_LEFT, Display::KeyType::Left},
    {SDLK_RIGHT, Display::KeyType::Right},
    {SDLK_UP, Display::KeyType::Up},
    {SDLK_DOWN, Display::KeyType::Down},
    {SDLK_KP_0, Display::KeyType::Numpad0},
    {SDLK_KP_1, Display::KeyType::Numpad1},
    {SDLK_KP_2, Display::KeyType::Numpad2},
    {SDLK_KP_3, Display::KeyType::Numpad3},
    {SDLK_KP_4, Display::KeyType::Numpad4},
    {SDLK_KP_5, Display::KeyType::Numpad5},
    {SDLK_KP_6, Display::KeyType::Numpad6},
    {SDLK_KP_7, Display::KeyType::Numpad7},
    {SDLK_KP_8, Display::KeyType::Numpad8},
    {SDLK_KP_9, Display::KeyType::Numpad9},
    {SDLK_F1, Display::KeyType::F1},
    {SDLK_F2, Display::KeyType::F2},
    {SDLK_F3, Display::KeyType::F3},
    {SDLK_F4, Display::KeyType::F4},
    {SDLK_F5, Display::KeyType::F5},
    {SDLK_F6, Display::KeyType::F6},
    {SDLK_F7, Display::KeyType::F7},
    {SDLK_F8, Display::KeyType::F8},
    {SDLK_F9, Display::KeyType::F9},
    {SDLK_F10, Display::KeyType::F10},
    {SDLK_F11, Display::KeyType::F11},
    {SDLK_F12, Display::KeyType::F12},
    {SDLK_F13, Display::KeyType::F13},
    {SDLK_F14, Display::KeyType::F14},
    {SDLK_F15, Display::KeyType::F15},
    {SDLK_PAUSE, Display::KeyType::Pause},
    {SDLK_BACKSPACE, Display::KeyType::BackSpace},
    {SDLK_BACKSLASH, Display::KeyType::BackSlash},
    {SDLK_SEMICOLON, Display::KeyType::SemiColon},
    {SDLK_RETURN, Display::KeyType::Return}
};

Display::SDL2Window::SDL2Window(std::string const &title, int framerateLimit, int width, int height)
{
    this->create(title, framerateLimit, width, height);
}

Display::SDL2Window::~SDL2Window()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Display::SDL2Window::create(std::string const &title, int framerateLimit, int width, int height)
{
    this->title = title;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        exit(84);
    }
    this->window = SDL_CreateWindow(
        this->title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (this->window == nullptr) {
        SDL_Quit();
        exit(84);
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        SDL_DestroyWindow(this->window);
        SDL_Quit();
        exit(84);
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderPresent(this->renderer);
}

std::unique_ptr<Display::IEvent> Display::SDL2Window::getEvent()
{
    SDL_Event SDL_event;
    Display::SDLEvent event;
    Display::KeyType type;

    SDL_PollEvent(&SDL_event);
        type = KeyToEventType.find(SDL_event.key.keysym.sym)->second;
        event.setType(type);
        return std::make_unique<Display::SDLEvent>(event);
}

std::string &Display::SDL2Window::getTitle()
{
    return this->title;
}

void Display::SDL2Window::setTitle(const std::string &title)
{
    this->title = title;
    SDL_SetWindowTitle(this->window, this->title.c_str());
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

void Display::SDL2Window::draw(std::unique_ptr<Display::ISprite> &sprite)
{
    SDL_Rect rect;

    Display::IVector2f pos = sprite->getPosition();
    Display::IIntRect size = sprite->getRect();
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size.width;
    rect.h = size.height;
    //Display::SDL2Texture &sdl2Texture = dynamic_cast<Display::SDL2Texture &>(sprite.getTexture());
    //SDL_Texture *texture = sdl2Texture.getSDLTexture();

    //SDL_RenderCopy(this->renderer, texture, nullptr, &rect);
}

void Display::SDL2Window::close()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

extern "C" std::unique_ptr<Display::IWindow> createWindow()
{
    return std::make_unique<Display::SDL2Window>();
}