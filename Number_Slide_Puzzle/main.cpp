#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    Game game;
    srand(static_cast<unsigned>(time(NULL)));

    while (game.running() && !game.getEndGame()) //loop
    {

        //Render
        game.render();

        //Update
        game.update();
    }

    return 0;
}
