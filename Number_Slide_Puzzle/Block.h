#ifndef BLOCK_H
#define BLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>


class Block
{
    public:
        Block(unsigned row, unsigned col);
        virtual ~Block();
    public:
        sf::RectangleShape getShape();

    protected:

    private:
        sf::RectangleShape shape;
        sf::Texture *texture;

        void setTexture();
};

#endif // BLOCK_H
