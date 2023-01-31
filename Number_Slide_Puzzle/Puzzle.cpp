#include "Puzzle.h"

Puzzle::Puzzle()
{
    //ctor
}

Puzzle::~Puzzle()
{
    //dtor
}


void Puzzle::newGame(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->blocks.push_back(Block(i,j));
        }
    }

}


void Puzzle::printBlocks(sf::RenderTarget &target){
    for (int i = 0; i < this->blocks.size(); i++){
        target.draw(this->blocks.at(i).getShape());
    }
}
