#include <iostream>
#include "Game.hpp"

int main(int argc, char** argv) {
  Game game;
  if (argc != 3) {
    std::cout << "usage: nibbler [width] [height]" << std::endl;
  } else {
    std::cout << *argv << std::endl;
    game.initialise(atoi(argv[1]), atoi(argv[2]));
    game.gameLoop();
  }
  return (0);
}