#include "Puzzle.h"

Puzzle::Puzzle()
{
    this->board.setSize(sf::Vector2f(259.f, 259.f));
    this->texture = new sf::Texture();
    this->setTexture();
}

Puzzle::~Puzzle()
{
    //dtor
}


void Puzzle::newGame(sf::VideoMode videoMode){
    this->board.setOrigin(this->board.getSize().x * 0.5, this->board.getSize().y * 0.5);
    this->board.setPosition(videoMode.width * 0.5, videoMode.height * 0.5);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 2 || i != 2){
                this->blocks.push_back(Block(videoMode, i,j));
            }
        }
    }
}


void Puzzle::printBoard(sf::RenderTarget &target){
    target.draw(this->board);
    for (int i = 0; i < this->blocks.size(); i++){
        target.draw(this->blocks.at(i).getShape());
    }
}



void Puzzle::setTexture(){
     if(!this->texture->loadFromFile("sprites/board.png"))
        std::cout << "ERROR::GAME::SETTEXTURE::Failed to load sprite!" << "\n";
    else
        this->board.setTexture(this->texture);
}


std::vector<Block>* Puzzle::getBlocks(){
    return &this->blocks;
}


void Puzzle::moveBlock(sf::Vector2f mousePosView){
    for(unsigned i = 0; i < this->blocks.size(); i++){
        // check if the block was clicked
        if(this->blocks[i].getShape().getGlobalBounds().contains(mousePosView)){
            this->blocks[i].moveRight();
        }
    }
}







