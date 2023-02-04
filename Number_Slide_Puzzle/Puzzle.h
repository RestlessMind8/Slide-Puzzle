#ifndef PUZZLE_H
#define PUZZLE_H
#include <SFML/Graphics.hpp>
#include "Block.h"


class Puzzle
{
    public:
        Puzzle();
        virtual ~Puzzle();
    public:
        void printBoard(sf::RenderTarget &target);
        void newGame(sf::VideoMode videoMode);
        std::vector<Block> *getBlocks();
        void moveBlock(sf::Vector2f mousePosView);
        bool gameOver();

    protected:

    private:
        std::vector<Block> blocks;
        sf::RectangleShape board;
        sf::Texture *texture;
        float blockSize;
        void setTexture();
        void shuffle();

};

#endif // PUZZLE_H
