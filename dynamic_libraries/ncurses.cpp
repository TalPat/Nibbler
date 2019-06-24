#include "Game.hpp"
#include <ncurses.h>

WINDOW * win;

void init(int x, int y) {
  initscr();
  win = newwin(y, x, 0, 0);
}