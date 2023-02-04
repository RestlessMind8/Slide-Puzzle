#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>


class Block
{
    public:
        Block(sf::VideoMode videoMode, unsigned row, unsigned col, bool empty);
        virtual ~Block();
    public:
        sf::RectangleShape getShape();
        int getValue();
        sf::Vector2i getIndex();
        void setIndex(sf::Vector2i index);
        void moveRight();
        void moveLeft();
        void moveDown();
        void moveUp();
        bool isEmpty();
        void setPosition(sf::Vector2f position);

    protected:

    private:
        sf::RectangleShape shape;
        sf::Texture *texture;

        int value;
        int row;
        int col;
        bool empty;

        //private functions
        void setTexture();
};

#endif // BLOCK_H
