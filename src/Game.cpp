#include "Game.hpp"
#include "Food.hpp"
#include <time.h>
#include <dlfcn.h>

Game::Game():
_libPath(""), _fps(60), _input(0), _gameOver(false), _gameStarted(false)
{
    srand(time(NULL));
}

Game::Game(const Game &obj){
    this->_libPath = obj._libPath;
    *(this->_food) = *(obj._food);
    this->_fps = obj._fps;
    this->_gameOver = obj._gameOver;
    this->_gameStarted = obj._gameStarted;
    this->_height = obj._height;
    this->_input = obj._input;
    this->_snake = std::list (obj._snake);
    this->_startTime = obj._startTime;
    this->_width = obj._width;
    this->_speed = obj._speed;
    srand(time(NULL));
}

Game::~Game(){
    delete _food;
    // delete snake list

}

Game& Game::operator=(const Game &obj){
    if (this != &obj) {
        this->_libPath = obj._libPath;
        *(this->_food) = *(obj._food);
        this->_fps = obj._fps;
        this->_gameOver = obj._gameOver;
        this->_gameStarted = obj._gameStarted;
        this->_height = obj._height;
        this->_input = obj._input;
        this->_snake = std::list (obj._snake);
        this->_startTime = obj._startTime;
        this->_width = obj._width;
        this->_speed = obj._speed;
    }
    return (*this);
}

void Game::initialise(int x, int y){
    this->_width = x;
    this->_height = y;
    this->_food = new Food(rand()%(x-1)+1, rand()%(y-1)+1);
    this->_snake.push_back(new Snake(x/2, y/2));
    this->_snake.push_back(new Snake(x/2, y/2 - 1));
    this->_snake.push_back(new Snake(x/2, y/2 - 2));
    if (dlopen(this->_libPath.c_str(), RTLD_LAZY));
}

void Game::gameLoop(){}
