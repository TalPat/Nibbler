#include "Game.hpp"
#include "Food.hpp"
#include <time.h>
#include <dlfcn.h>
#include <iostream>
#include <unistd.h>

Game::Game():
_libPath("./dlib3/sdl.dylib"), _fps(60), _input(0), _gameOver(false), _gameStarted(false) //.dylib for mac & .so for linux
{
    srand(time(NULL));
    this->_gameState = new GameState;
    this->_gameState->food = new FoodSt;
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
    this->_gameState = obj._gameState;
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
        this->_gameState = obj._gameState;
    }
    return (*this);
}

void Game::initialise(int x, int y){
    // typedef void (*render_t)(GameState*), (*init_t)(int, int), (*endGame_t)(void), (*closeWindow_t)(void);
    // typedef int (*getInput_t)(void);

    this->_width = x;
    this->_height = y;
    bool check = true;
    int fx, fy;
    while (check) {
        fy = rand()%(this->_height);
        fx = rand()%(this->_width); 
        check = false;
        for (std::list<Snake*>::iterator it=this->_snake.begin(); it!=(this->_snake.end()); ++it) {
            if (fx == (*it)->getPosx() && fy == (*it)->getPosy()) {
                check = true;
                break;
            }
        }
    }

    this->_food = new Food(fx, fy);
    this->_snake.push_back(new Snake(x/2, y/2));
    this->_snake.push_back(new Snake(x/2, y/2 + 1));
    this->_snake.push_back(new Snake(x/2, y/2 + 2));
    this->_snake.push_back(new Snake(x/2, y/2 + 3));
    this->_snake.push_back(new Snake(x/2, y/2 + 4));
    //* */for (size_t i = 0; i < 9999; i++) this->_snake.push_back(new Snake(x/2, y/2 + 4));
    this->_startTime = std::chrono::high_resolution_clock::now();
    this->_t1 = this->_startTime;
    this->_speed = 5.0;
    // if ((this->_libhandle = dlopen(this->_libPath.c_str(), RTLD_LAZY))) {
    //     this->render = (render_t) dlsym(this->_libhandle, "render");
    //     this->init = (init_t) dlsym(this->_libhandle, "init");
    //     this->endGame = (endGame_t) dlsym(this->_libhandle, "endGame");
    //     this->closeWindow = (closeWindow_t) dlsym(this->_libhandle, "closeWindow");
    //     this->getInput = (getInput_t) dlsym(this->_libhandle, "getInput");
    // } else {
    //     std::cerr << "Failed to load " + this->_libPath << std::endl;
    //     exit (1);
    // }
    this->loadLib();
    this->init(this->_width, this->_height);
}

void Game::gameLoop(){
    int i = 0;
    int loopDelay = 1 / this->_speed;

    while (1){

        this->_t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(this->_t2 - this->_t1);
        if (time_span.count() > 1.0 / this->_speed) {
            this->handleInput(this->_input);
            this->_input = -1;
            this->checkCollision();
            this->_t1 = std::chrono::high_resolution_clock::now();
        }
        this->updateGameState();
        this->render(this->_gameState);
        usleep(loopDelay);
        if ((i = this->getInput()) != -1)
        this->_input = i;
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
        if (this->_snake.front()->getDirection() != 2)
            this->_snake.front()->setDirection(0);
        this->moveSnake();
        break;
    case 1:
        if (this->_snake.front()->getDirection() != 3)
            this->_snake.front()->setDirection(1);
        this->moveSnake();
        break;
    case 2:
        if (this->_snake.front()->getDirection() != 0)
            this->_snake.front()->setDirection(2);
        this->moveSnake();
        break;
    case 3:
        if (this->_snake.front()->getDirection() != 1)
            this->_snake.front()->setDirection(3);
        this->moveSnake();
        break;
    case 4:
        this->closeWindow();
        exit(1);
        break;
    case 5:
        while (1) {
            if (this->getInput() == 5) {
                break;
            }
        }
        break;
    case 6:
        this->closeWindow();
        dlclose(this->_libhandle);
        this->_libPath = "dlib1/ncurses.dylib";
        this->loadLib();
        this->init(this->_width, this->_height);
        break;
    case 7:
        this->closeWindow();
        dlclose(this->_libhandle);
        this->_libPath = "dlib2/???.dylib";
        this->loadLib();
        this->init(this->_width, this->_height);
        break;
    case 8:
        this->closeWindow();
        dlclose(this->_libhandle);
        this->_libPath = "dlib3/sdl.dylib";
        this->loadLib();
        this->init(this->_width, this->_height);
        break;
    default:
        this->moveSnake();
        break;
    }
}

void Game::moveSnake() {
    std::list<Snake*>::reverse_iterator ritNext = this->_snake.rbegin();
    ritNext++;
    switch (this->_snake.front()->getDirection())
    {
    case 0:
        for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
            (*rit)->setPosx((*ritNext)->getPosx());
            (*rit)->setPosy((*ritNext)->getPosy());
            ++ritNext;
        }
        this->_snake.front()->setPosy(this->_snake.front()->getPosy() - 1);
        break;
    case 1:
        for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
            (*rit)->setPosx((*ritNext)->getPosx());
            (*rit)->setPosy((*ritNext)->getPosy());
            ++ritNext;
        }
        this->_snake.front()->setPosx(this->_snake.front()->getPosx() + 1);
        break;
    case 2:
        for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
            (*rit)->setPosx((*ritNext)->getPosx());
            (*rit)->setPosy((*ritNext)->getPosy());
            ++ritNext;
        }
        this->_snake.front()->setPosy(this->_snake.front()->getPosy() + 1);
        break;
    case 3:
        for (std::list<Snake*>::reverse_iterator rit=this->_snake.rbegin(); ritNext!=(this->_snake.rend()); ++rit) {
            (*rit)->setPosx((*ritNext)->getPosx());
            (*rit)->setPosy((*ritNext)->getPosy());
            ++ritNext;
        }
        this->_snake.front()->setPosx(this->_snake.front()->getPosx() - 1);
        break;
    
    default:
        break;
    }
}

void Game::updateGameState() {
    this->_gameState->food->x = this->_food->getPosx();
    this->_gameState->food->y = this->_food->getPosy();
    this->_gameState->snake.clear();
    for (std::list<Snake*>::iterator it=this->_snake.begin(); it!=(this->_snake.end()); ++it) {
        SnakeSt* mySnake = new SnakeSt;
        mySnake->x = (*it)->getPosx();
        mySnake->y = (*it)->getPosy();
        mySnake->direction = (*it)->getDirection();
        this->_gameState->snake.push_back(mySnake);
    }
}

void Game::checkCollision() {
    int snakex = this->_snake.front()->getPosx();
    int snakey = this->_snake.front()->getPosy();
    std::list<Snake*>::iterator it=this->_snake.begin();
    it++;

    if (snakex < 0 || snakex >= this->_width || snakey < 0 || snakey >= this->_height) {
        this->closeWindow();
        exit(1);
    }
    for (; it!=(this->_snake.end()); ++it) {
        if (snakex == (*it)->getPosx() && snakey == (*it)->getPosy()) {
            this->closeWindow();
            exit(1);
        }
    }
    if (snakex == this->_food->getPosx() && snakey == this->_food->getPosy()) {
        delete this->_food;
        bool check = true;
        int x, y;
        while (check) {
            y = rand()%(this->_height);
            x = rand()%(this->_width); 
            check = false;
            for (std::list<Snake*>::iterator it=this->_snake.begin(); it!=(this->_snake.end()); ++it) {
                if (x == (*it)->getPosx() && y == (*it)->getPosy()) {
                    check = true;
                    break;
                }
            }
        }

        this->_food = new Food(x, y);
        this->_snake.push_back(new Snake(-1, -1));
    }
}

void Game::loadLib() {
    typedef void (*render_t)(GameState*), (*init_t)(int, int), (*endGame_t)(void), (*closeWindow_t)(void);
    typedef int (*getInput_t)(void);
    
    if ((this->_libhandle = dlopen(this->_libPath.c_str(), RTLD_LAZY))) {
        this->render = (render_t) dlsym(this->_libhandle, "render");
        this->init = (init_t) dlsym(this->_libhandle, "init");
        this->endGame = (endGame_t) dlsym(this->_libhandle, "endGame");
        this->closeWindow = (closeWindow_t) dlsym(this->_libhandle, "closeWindow");
        this->getInput = (getInput_t) dlsym(this->_libhandle, "getInput");
    } else {
        std::cerr << "Failed to load " + this->_libPath << std::endl;
        exit (1);
    }
}

Food* Game::getFood() {
    return (this->_food);
}

std::list<Snake*> Game::getSnake() {
    return (this->_snake);
}
