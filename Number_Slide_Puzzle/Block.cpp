#include "Block.h"

Block::Block(unsigned row, unsigned col)
{
    this->shape.setSize(sf::Vector2f(80.f, 80.f));
    this->shape.setPosition(row * 80.f, col * 80.f);
    this->texture = new sf::Texture();
    setTexture();
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
