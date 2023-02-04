#include "Block.h"

Block::Block(sf::VideoMode videoMode, unsigned row, unsigned col, bool empty)
{
    this->shape.setSize(sf::Vector2f(80.f, 80.f));
    this->shape.setPosition((videoMode.width * 0.5) - 130 + col * 80.f, (videoMode.height * 0.5) - 130 + row * 80.f);
    this->texture = new sf::Texture();
    this->value = 1 + 3*row + col;
    this->row = row;
    this->col = col;
    setTexture();
    this->empty = empty;
}

Block::~Block()
{
    //dtor
}


void Block::setTexture(){
    if(!this->texture->loadFromFile("sprites/block.png"))
        std::cout << "ERROR::GAME::SETTEXTURE::Failed to load sprite!" << "\n";
    else
        this->shape.setTexture(this->texture);
}


sf::RectangleShape Block::getShape(){
    return this->shape;
}


void Block::setPosition(sf::Vector2f position){
    this->shape.setPosition(position);
}


int Block::getValue(){
    return this->value;
}


sf::Vector2i Block::getIndex(){
    return sf::Vector2i(this->row, this->col);
}

void Block::setIndex(sf::Vector2i index){
    this->row = index.x;
    this->col = index.y;
}


void Block::moveRight(){
    if(this->col < 2){
        this->shape.move(80, 0);
        this->col++;
    }
}


void Block::moveLeft(){
    if(this->col > 0){
        this->shape.move(-80, 0);
        this->col--;
    }
}


void Block::moveUp(){
    if(this->row > 0){
        this->shape.move(0, -80);
        this->row--;
    }
}


void Block::moveDown(){
    if(this->row < 2){
        this->shape.move(0, 80);
        this->row++;
    }
}


bool Block::isEmpty(){
    return this->empty;
}






