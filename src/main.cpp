#include <iostream>
#include "Game.hpp"

bool check_string(const char* string) {
  const int string_len = strlen(string);
  for(int i = 0; i < string_len; ++i) {
    if(!isdigit(string[i])) 
      return false;
  }
  return true;
}

int main(int argc, char** argv) {
  Game game;
  if (argc != 3) {
    std::cout << "usage: nibbler [width] [height]" << std::endl;
  } else {
    if (
      check_string(argv[1]) &&
      check_string(argv[2]) &&
      atoi(argv[1]) > 10 &&
      atoi(argv[2]) > 10 &&
      atoi(argv[1]) < 100 &&
      atoi(argv[2]) < 100
    ) {
      std::cout << *argv << std::endl;
      game.initialise(atoi(argv[1]), atoi(argv[2]));
      game.gameLoop();
    } else {
      std::cout << "Width and Height must lie between 10 and 100" << std::endl;
    }
  }
  return (0);
}