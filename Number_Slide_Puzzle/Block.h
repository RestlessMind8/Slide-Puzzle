#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>


class Block
{
    public:
        Block(sf::VideoMode videoMode, unsigned row, unsigned col);
        virtual ~Block();
    public:
        sf::RectangleShape getShape();
        int getValue();
        sf::Vector2i getIndex();
        void moveRight();

    protected:

    private:
        sf::RectangleShape shape;
        sf::Texture *texture;
        int value;
        int row;
        int col;
        bool up, down, left, right;
        void setTexture();
};

#endif // BLOCK_H
