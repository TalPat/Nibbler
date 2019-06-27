#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <list>
#include <chrono>
#include "Food.hpp"
#include "Snake.hpp"
#include "GameState.hpp"

class Game
{
private:
  std::string _libPath;
  int _width, _height, _fps, _input;
  double _speed;
  std::chrono::high_resolution_clock::time_point _startTime, _t1, _t2;
  Food* _food;
  std::list<Snake*> _snake;
  bool _gameOver, _gameStarted;
  void (*render)(GameState*), (*init)(int, int), (*endGame)(void), (*closeWindow)(void), *_libhandle;
  int (*getInput)(void);
  GameState* _gameState;
public:
  Game();
  Game(const Game &obj);
  ~Game();
  Game& operator=(const Game &obj);

  void initialise(int x, int y);
  void gameLoop();
  void checkCollision();
  void handleInput(int command);
  void moveSnake();
  void updateGameState();

  Food* getFood(void);
  std::list<Snake*> getSnake(void);
};

#endif
