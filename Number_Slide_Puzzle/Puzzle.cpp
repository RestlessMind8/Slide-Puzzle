#include "Puzzle.h"

Puzzle::Puzzle()
{
    srand(static_cast<unsigned>(time(NULL)));
    this->board.setSize(sf::Vector2f(260.f, 260.f));
    this->texture = new sf::Texture();
    this->setTexture();
}

Puzzle::~Puzzle()
{
    //dtor
}


void Puzzle::newGame(sf::VideoMode videoMode){
    this->board.setOrigin(this->board.getSize().x * 0.5, this->board.getSize().y * 0.5);
    this->board.setPosition(videoMode.width * 0.5 + 10, videoMode.height * 0.5);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 2 || i != 2){
                this->blocks.push_back(Block(videoMode, i,j, false));
            }else
                this->blocks.push_back(Block(videoMode, i, j, true));
        }
    }
    this->shuffle();
}





void Puzzle::printBoard(sf::RenderTarget &target){
    target.draw(this->board);
    for (unsigned i = 0; i < this->blocks.size(); i++){
        if(!this->blocks[i].isEmpty()){
            target.draw(this->blocks[i].getShape());
        }
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
    for(int i = 0; i < this->blocks.size(); i++){
        // check if the block was clicked
        if(!this->blocks[i].isEmpty() && this->blocks[i].getShape().getGlobalBounds().contains(mousePosView)){
            if((i - 3) >= 0 && this->blocks[i - 3].isEmpty()){
                this->blocks[i - 3].moveDown();
                this->blocks[i].moveUp();
                std::swap(this->blocks[i], this->blocks[i - 3]);
            }else if((i + 3) < 9 && this->blocks[i + 3].isEmpty()){
                this->blocks[i + 3].moveUp();
                this->blocks[i].moveDown();
                std::swap(this->blocks[i], this->blocks[i + 3]);
            }else if(this->blocks[i].getIndex().y != 2 && ((i + 1) < 9 && this->blocks[i + 1].isEmpty())){
                this->blocks[i + 1].moveLeft();
                this->blocks[i].moveRight();
                std::swap(this->blocks[i], this->blocks[i + 1]);
            }else if(this->blocks[i].getIndex().y != 0 && ((i - 1) >= 0 && this->blocks[i - 1].isEmpty())){
                this->blocks[i - 1].moveRight();
                this->blocks[i].moveLeft();
                std::swap(this->blocks[i], this->blocks[i - 1]);
            }
            break;
        }
    }
}


void Puzzle::restart(){
    shuffle();
}


void Puzzle::shuffle(){
    for (unsigned i = 0; i < this->blocks.size() - 4; i++)
    {
        int j = i + rand() % (this->blocks.size() - i);
        sf::Vector2i index = this->blocks[i].getIndex();
        sf::Vector2f position = this->blocks[i].getShape().getPosition();

        this->blocks[i].setIndex(this->blocks[j].getIndex());
        this->blocks[j].setIndex(index);

        this->blocks[i].setPosition(this->blocks[j].getShape().getPosition());
        this->blocks[j].setPosition(position);

        std::swap(this->blocks[i], this->blocks[j]);
    }
}


bool Puzzle::gameOver(){
    for(unsigned i = 0; i < this->blocks.size() - 1; i++){
        if(this->blocks[i].getValue() > this->blocks[i+1].getValue()){
            return false;
        }
    }
    return true;
}







