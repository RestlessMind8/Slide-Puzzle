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
    this->shuffle();
}


void Puzzle::printBoard(sf::RenderTarget &target){
    target.draw(this->board);
    for (unsigned i = 0; i < this->blocks.size(); i++){
        target.draw(this->blocks[i].getShape());
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
            sf::Vector2f blockPosition = this->blocks[i].getShape().getPosition();
            sf::Vector2f blockCenterPosition = sf::Vector2f(blockPosition.x + this->blockSize * 0.5, blockPosition.y + this->blockSize * 0.5);
            int j = i;

        }
    }
}


void Puzzle::shuffle(){
    for (unsigned i = 0; i < this->blocks.size() - 1; i++)
    {
        int j = i + rand() % (this->blocks.size() - i);
        sf::Vector2i index = this->blocks[i].getIndex();
        this->blocks[i].setIndex(this->blocks[j].getIndex());
        this->blocks[j].setIndex(index);
        std::swap(this->blocks[i], this->blocks[j]);
    }
}








