#include "../includes/Game.hpp"
#include <ncurses.h>
#include <iostream>

WINDOW * win;

extern "C" void init(int x, int y) {
  initscr();
  curs_set(0);
  refresh();
  win = newwin(y, x, 0, 0);
  noecho();
  box(win, 0, 0);
  keypad(stdscr, true);
  mvwprintw(win, y/2, (x/2)-(17/2), "PREPARE YOURSELF");
  wrefresh(win);
  //getch();
  nodelay(stdscr, true);
}

extern "C" void render(Game* game) {
  std::list<Snake*>::iterator it;
  werase(win);
  box(win, 0 ,0);
  /* */char c[2] = {game->getSnake().size() + '0'};
  /* */ mvwprintw(win, 1, 1, c);
  for (it = game->getSnake().begin(); it != game->getSnake().end(); it++) {
    /* */std::cout << (*it)->getPosy() << std::endl;
    mvwprintw(win, (*it)->getPosy(), (*it)->getPosx(), "O");
  }
    //* */std::cout << "y" << std::endl;
  mvwprintw(win, game->getFood()->getPosy(), game->getFood()->getPosx(), "*");
  wrefresh(win);
}

extern "C" void endGame() {

}

extern "C" void closeWindow() {

}

extern "C" int getInput() {
  int ch = getch();
  switch (ch)
  {
  case KEY_UP:
    return(0);
    break;
  case KEY_RIGHT:
    return(1);
    break;
  case KEY_DOWN:
    return(2);
    break;
  case KEY_LEFT:
    return(3);
    break;
  case 'q':
    return(4);
    break;
  case ' ':
    return(5);
    break;
  case '1':
    return(6);
    break;
  case '2':
    return(7);
    break;
  case '3':
    return(8);
    break;
  default:
    return (-1);
    break;
  }
}