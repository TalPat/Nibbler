#include "GameState.hpp"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <sstream>

WINDOW * win;
WINDOW* scoreBox;

extern "C" void init(int x, int y) {
  initscr();
  curs_set(0);
  refresh();
  win = newwin(y+2, x+2, 0, 0);
  scoreBox = newwin(3, x+2, y+2, 0);
  noecho();
  box(win, 0, 0);
  box(scoreBox, 0, 0);
  keypad(stdscr, true);
  mvwprintw(win, y/2, (x/2)-(17/2), "PREPARE YOURSELF");
  wrefresh(win);
  wrefresh(scoreBox);
  //getch();
  nodelay(stdscr, true);
}

extern "C" void render(GameState* game) {
  std::list<SnakeSt*>::iterator it = game->snake.begin();
  werase(win);
  box(win, 0 ,0);
  switch ((*it)->direction)
  {
    case 0:
      mvwprintw(win, (*it)->y + 1, (*it)->x + 1, "^");
      break;
    case 1:
      mvwprintw(win, (*it)->y + 1, (*it)->x + 1, ">");
      break;
    case 2:
      mvwprintw(win, (*it)->y + 1, (*it)->x + 1, "v");
      break;
    case 3:
      mvwprintw(win, (*it)->y + 1, (*it)->x + 1, "<");
      break;
    default:
      break;
  }
  it++;
  for (; it != game->snake.end(); it++) {
    if((*it)->x > -1)
    mvwprintw(win, (*it)->y + 1, (*it)->x + 1, "O");
  }
  mvwprintw(win, game->food->y + 1, game->food->x + 1, "*");
  wrefresh(win);

  werase(scoreBox);
  box(scoreBox,0, 0);

  std::string out_string;
  std::stringstream ss;
  ss << game->score;
  out_string = ss.str();
  mvwprintw(scoreBox, 1, 1, out_string.c_str());
  wrefresh(scoreBox);
}

extern "C" void endGame() {

}

extern "C" void closeWindow() {
  /* */sleep(2);
  werase(win);
  wrefresh(win);
  endwin();
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