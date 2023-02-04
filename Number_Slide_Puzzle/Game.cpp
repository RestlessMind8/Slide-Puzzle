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
    this->play();
}


void Game::render(){
    this->window->clear(sf::Color(226, 183, 128));
    this->puzzle->printBoard(*this->window);
    this->renderText();
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
    this->videoMode.width = 340;
    this->endGame = false;
    this->mouseHeld = false;
    this->puzzle = new Puzzle();
    this->puzzle->newGame(this->videoMode);
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
    this->text.setFont(this->font);
    this->text.setCharacterSize(35);
    this->text.setFillColor(sf::Color::Black);
}


void Game::renderText(){
    std::vector<Block> *blocks = this->puzzle->getBlocks();
    std::stringstream ss;
    sf::Vector2i blockIndex;
    float offsetX = (videoMode.width * 0.5) - 100;
    float offsetY = (videoMode.height * 0.5) - 115;
    for(unsigned i = 0; i < blocks->size(); i++){
        if(!blocks->at(i).isEmpty()){
            blockIndex = blocks->at(i).getIndex();
            ss.str("");
            ss << blocks->at(i).getValue();
            this->text.setString(ss.str());
            this->text.setPosition(
                offsetX + blockIndex.y*80,
                offsetY + blockIndex.x*80
            );
            this->window->draw(this->text);
        }
    }
}


void Game::play(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(!this->mouseHeld){
            this->mouseHeld = true;
            this->puzzle->moveBlock(this->mousePosView);
        }
    }else{
        this->mouseHeld = false;
    }
}
