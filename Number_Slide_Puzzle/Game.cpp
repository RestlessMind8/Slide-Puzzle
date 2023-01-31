#include "Game.h"

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}


void Game::update(){
    this->pollEvents();
    this->updateMousePosition();
}


void Game::render(){
    this->window->clear(sf::Color(226, 183, 128));
    this->puzzle->printBlocks(*this->window);
    this->window->display();
}


void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}


void Game::initVariables(){
    this->videoMode.height = 500;
    this->videoMode.width = 450;
    this->endGame = false;
    this->mouseHeld = false;
    this->puzzle = new Puzzle();
    this->puzzle->newGame();
}


void Game::initWindow(){
    this->window = new sf::RenderWindow(this->videoMode, "Slide Puzzle", sf::Style::Close);
    this->window->setFramerateLimit(60);
}


void Game::initFonts(){
    if(!this->font.loadFromFile("fonts/RobotoCondensed-Regular.ttf")){
        std::cout << "ERROR::GAME::INIFONTS::Failed to load font!" << "\n";
    }
}


void Game::updateMousePosition(){
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}


const bool Game::getEndGame() const{
    return this->endGame;
}


const bool Game::running() const{
    return this->window->isOpen();
}


void Game::initText(){
    std::stringstream ss;
    ss << "NONE";
    this->text.setFont(this->font);
    this->text.setCharacterSize(25);
    this->text.setString(ss.str());
}
