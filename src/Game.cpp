#include "Game.hpp"
#include "Food.hpp"
#include <time.h>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

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
    this->_snake = std::list<Snake*> (obj._snake);
    this->_startTime = obj._startTime;
    this->_width = obj._width;
    this->_speed = obj._speed;
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
        this->_snake = std::list<Snake*> (obj._snake);
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
    this->_startTime = std::chrono::high_resolution_clock::now();
    this->_t1 = this->_startTime;
    this->_speed = 1.0;
    //if (dlopen(this->_libPath.c_str(), RTLD_LAZY)); //assign functions to pointers
}

void Game::gameLoop(){
    int i = 0;
    int loopDelay = 100 / this->_speed;
    /* dont keep */long x = 0; 
    while (1){

        this->_t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(this->_t2 - this->_t1);
        if (time_span.count() > 1.0 / this->_speed) {
            //get input, handle input, update game state
            this->_t1 = std::chrono::high_resolution_clock::now();
            /*  dont keep */ std::cout << "Game cycles" << i << std::endl; i++; std::cout << x << std::endl; x = 0; std::cout << time_span.count() << std::endl; x = 0;
        }
        //render
        /* dont keep */x++; 
        usleep(loopDelay);
    }

}

void Game::handleInput(int command) {
    /*
        -1: no input
        0: up
        1: right
        2: down
        3: left
        4: quit
        5: pause
        6: gl 1
        7: gl 2
        8: gl 3
    */
    switch (command)
    {
    case 0:
        if (this->_snake.front()->getDirection() != 0) {
            std::list<Snake*>::reverse_iterator ritNext = this->_snake.rbegin();
            ritNext++;
            for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
                (*rit)->setPosx((*ritNext)->getPosx());
                (*rit)->setPosy((*ritNext)->getPosy());
                ++ritNext;
            }
            this->_snake.front()->setDirection(0);
            this->_snake.front()->setPosy(this->_snake.front()->getPosy() - 1);
        }
        break;
    case 1:
        if (this->_snake.front()->getDirection() != 1) {
            std::list<Snake*>::reverse_iterator ritNext = this->_snake.rbegin();
            ritNext++;
            for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
                (*rit)->setPosx((*ritNext)->getPosx());
                (*rit)->setPosy((*ritNext)->getPosy());
                ++ritNext;
            }
            this->_snake.front()->setDirection(1);
            this->_snake.front()->setPosx(this->_snake.front()->getPosx() + 1);
        }
        break;
    case 2:
        if (this->_snake.front()->getDirection() != 2) {
            std::list<Snake*>::reverse_iterator ritNext = this->_snake.rbegin();
            ritNext++;
            for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
                (*rit)->setPosx((*ritNext)->getPosx());
                (*rit)->setPosy((*ritNext)->getPosy());
                ++ritNext;
            }
            this->_snake.front()->setDirection(2);
            this->_snake.front()->setPosy(this->_snake.front()->getPosy() + 1);
        }
        break;
    case 3:
        if (this->_snake.front()->getDirection() != 3) {
            std::list<Snake*>::reverse_iterator ritNext = this->_snake.rbegin();
            ritNext++;
            for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
                (*rit)->setPosx((*ritNext)->getPosx());
                (*rit)->setPosy((*ritNext)->getPosy());
                ++ritNext;
            }
            this->_snake.front()->setDirection(3);
            this->_snake.front()->setPosx(this->_snake.front()->getPosx() - 1);
        }
        break;
    default:
        break;
    }
}
