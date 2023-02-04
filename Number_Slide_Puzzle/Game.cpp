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


void Game::render(){
    this->window->clear(sf::Color(226, 183, 128));
    this->puzzle->printBoard(*this->window);
    this->showTime();
    this->renderText();
    this->window->display();
}


void Game::update(){
    this->pollEvents();
    this->updateMousePosition();
    this->play();
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
    this->started = false;
    this->clock = sf::Clock();
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
    this->text.setFillColor(sf::Color::Black);
}


void Game::renderText(){
    std::vector<Block> *blocks = this->puzzle->getBlocks();
    std::stringstream ss;
    sf::Vector2i blockIndex;
    this->text.setCharacterSize(35);
    float offsetX = (videoMode.width * 0.5) - 90;
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
    if(!started || this->puzzle->gameOver()){
        ss.str("");
        this->puzzle->gameOver()  ? ss << "New Game" : ss << "Start Game" ;
        this->text.setString(ss.str());
        this->text.setPosition((this->videoMode.width - this->text.getCharacterSize() * 4) * 0.5, this->videoMode.height - 100);
        this->window->draw(this->text);
    }
}


void Game::play(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(!started || this->puzzle->gameOver()){
            if(this->text.getGlobalBounds().contains(mousePosView)){
                started = !started;
                this->puzzle->restart();
            }
        }else if(!this->mouseHeld){
            this->mouseHeld = true;
            this->puzzle->moveBlock(this->mousePosView);
        }
    }else{
        this->mouseHeld = false;
    }
}


void Game::showTime(){
    std::stringstream ss;
    ss.str("");
    if(this->puzzle->gameOver()){
        ss << this->score;
        this->clock.restart();
    }else{
        if(started){
        this->score = roundf(10 * this->clock.getElapsedTime().asSeconds()) / 10;
        ss << this->score;
        }else{
            ss << "0.0" ;
        }
    }
    this->text.setString(ss.str());
    this->text.setCharacterSize(25);
    this->text.setPosition((this->videoMode.width - this->text.getCharacterSize()) * 0.5, 50);
    this->window->draw(this->text);
}
















