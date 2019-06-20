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
  int _width, _height, _fps, _input;
  long _startTime;
  Food* food;
  std::list<Snake*> snake;
  bool _gameOver;
public:
  Game();
  Game(const Game &obj);
  ~Game();
  Game& operator=(const Game &obj);

  void initialise(int x, int y);
  void gameLoop();
  int getInput();
};

#endif
