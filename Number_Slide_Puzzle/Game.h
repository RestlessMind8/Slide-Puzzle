#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Puzzle.h"
#include <math.h>

class Game
{
    public:
        Game();
        virtual ~Game();

    public:
        void update();
        void render();
        const bool running() const;
        const bool getEndGame() const;

    protected:

    private:
        sf::RenderWindow *window;
        sf::Event ev;
        sf::VideoMode videoMode;
        sf::Clock clock;
        sf::Font font;
        sf::Text text;

        //mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //game logic
        bool endGame;
        bool mouseHeld;
        bool started;
        Puzzle *puzzle;
        float score;

        //private functions
        void initVariables();
        void initWindow();
        void initFonts();
        void initText();
        void pollEvents();
        void updateMousePosition();
        void renderText();
        void play();
        void showTime();
};

#endif // GAME_H
