#include "GameState.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Window* win;
SDL_Surface* surface;

extern "C" void init(int x, int y) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize. Error: " << SDL_GetError() << std::endl;
  } else {
    win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x * 10, y * 10, SDL_WINDOW_SHOWN);
    if (win == NULL) {
      std::cout << "SDL window could not initialize. Error: " << SDL_GetError() << std::endl;
    } else {
      surface = SDL_GetWindowSurface(win);
      SDL_Delay(2000);
    }
  }

}

extern "C" void render(GameState* game) {
  std::list<SnakeSt*>::iterator it;
  //clear window

  //background/borders

  //iterate through snake obj and  place

  //

  //render
}

extern "C" void endGame() {

}

extern "C" void closeWindow() {
  SDL_DestroyWindow(win);
  SDL_Quit();
}

extern "C" int getInput() {
  return (-1);
}