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
        void printBlocks(sf::RenderTarget &target);
        void newGame();

    protected:

    private:
        std::vector<Block> blocks;

};

#endif // PUZZLE_H
