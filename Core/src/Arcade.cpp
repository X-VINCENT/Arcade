/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "Handler.hpp"
#include "DLLoader.hpp"

std::vector<std::map <std::string, std::string>> getGames()
{
    std::vector<std::map <std::string, std::string>> games = {
        {
            {"name", "Snake"},
            {"path", "lib/arcade_snake.so"}
        },
        {
            {"name", "Nibbler"},
            {"path", "lib/arcade_nibbler.so"}
        },
        {
            {"name", "Pacman"},
            {"path", "lib/arcade_pacman.so"}
        },
        {
            {"name", "Qix"},
            {"path", "lib/arcade_qix.so"}
        },
        {
            {"name", "Centipede"},
            {"path", "lib/arcade_centipede.so"}
        },
        {
            {"name", "SolarFox"},
            {"path", "lib/arcade_solarfox.so"}
        }
    };
    std::vector<std::map <std::string, std::string>> existingGames = {};

    for (auto &game : games) {
        FILE *file = fopen(game["path"].c_str(), "r");
        if (file == nullptr)
            continue;
        fclose(file);

        Core::DLLoader loader(game["path"]);

        std::string const &createGameFn = "createGame";
        using gameFnPtr = std::unique_ptr<Game::IGameModule> (*)(Display::IFactory &);
        gameFnPtr createGamePtr = nullptr;
        try {
            createGamePtr = loader.template getInstance<gameFnPtr>(createGameFn);
            if (!createGamePtr)
                throw std::runtime_error("No createGame function found in " + game["path"]);
        } catch (std::exception &e) {
            std::cerr << "Library " << game["path"] << " is not a valid arcade game library." << std::endl;
            std::cerr << "Check documentation here: https://arcade-4.gitbook.io/documentation/game-library/overview" << std::endl;
            exit(84);
        }

        existingGames.push_back(game);
    }
    return existingGames;
}

std::vector<std::map <std::string, std::string>> getGraphics()
{
    std::vector<std::map <std::string, std::string>> graphics = {
        {
            {"name", "NCurses"},
            {"path", "lib/arcade_ncurses.so"}
        },
        {
            {"name", "NDK++"},
            {"path", "lib/arcade_ndk++.so"}
        },
        {
            {"name", "aa-lib"},
            {"path", "lib/arcade_aalib.so"}
        },
        {
            {"name", "libcaca"},
            {"path", "lib/arcade_libcaca.so"}
        },
        {
            {"name", "Allegro5"},
            {"path", "lib/arcade_allegro5.so"}
        },
        {
            {"name", "Xlib"},
            {"path", "lib/arcade_xlib.so"}
        },
        {
            {"name", "GTK+"},
            {"path", "lib/arcade_gtk+.so"}
        },
        {
            {"name", "SFML"},
            {"path", "lib/arcade_sfml.so"}
        },
        {
            {"name", "SDL2"},
            {"path", "lib/arcade_sdl2.so"}
        },
        {
            {"name", "Irrlicht"},
            {"path", "lib/arcade_irrlicht.so"}
        },
        {
            {"name", "OpenGL"},
            {"path", "lib/arcade_opengl.so"}
        },
        {
            {"name", "Vulkan"},
            {"path", "lib/arcade_vulkan.so"}
        },
        {
            {"name", "Qt5"},
            {"path", "lib/arcade_qt5.so"}
        }
    };
    std::vector<std::map <std::string, std::string>> existingGraphics = {};

    for (auto &graphic : graphics) {
        FILE *file = fopen(graphic["path"].c_str(), "r");
        if (file == nullptr)
            continue;
        fclose(file);

        Core::DLLoader loader(graphic["path"]);

        std::string const &createFactoryFn = "createFactory";
        using factoryFnPtr = std::unique_ptr<Display::IFactory> (*)();
        factoryFnPtr createFactoryPtr = nullptr;
        try {
            createFactoryPtr = loader.template getInstance<factoryFnPtr>(createFactoryFn);
            if (!createFactoryPtr)
                throw std::runtime_error("No createFactory function found in " + graphic["path"]);
        } catch (std::exception &e) {
            std::cerr << "Library " << graphic["path"] << " is not a valid arcade graphic library." << std::endl;
            std::cerr << "Check documentation here: https://arcade-4.gitbook.io/documentation/display-library/overview" << std::endl;
            exit(84);
        }

        existingGraphics.push_back(graphic);
    }
    return existingGraphics;
}

int arcade(std::string const &displayLibPath)
{
    std::vector<std::map <std::string, std::string>> games = getGames();
    std::vector<std::map <std::string, std::string>> graphics = getGraphics();

    Core::Handler handler(displayLibPath, games, graphics);

    handler.loop();

    return SUCCESS;
}
