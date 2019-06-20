#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <list>
#include "Food.hpp"
#include "Snake.hpp"

class Game
{
private:
  std::string _libPath;
  int _width, _height, _fps, _input, _speed;
  long _startTime;
  Food* _food;
  std::list<Snake*> _snake;
  bool _gameOver, _gameStarted;
  void (*render)(Game), (*init)(int, int), (*endGame)(void);
  int (*getInput)(void);
public:
  Game();
  Game(const Game &obj);
  ~Game();
  Game& operator=(const Game &obj);

  void initialise(int x, int y);
  void gameLoop();
};

#endif
