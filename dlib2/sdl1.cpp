#include "GameState.hpp"
#include <SDL.h>
#include <iostream>

SDL_Window* win;
SDL_Renderer* sdlRender;

void drawtTri(int x, int y, int dir) {
  switch (dir)
  {
  case 0:
    SDL_RenderDrawLine(sdlRender, x+5, y, x+9, y+9);
    SDL_RenderDrawLine(sdlRender, x+5, y, x, y+9);
    break;
  case 1:
    SDL_RenderDrawLine(sdlRender, x, y, x+9, y+5);
    SDL_RenderDrawLine(sdlRender, x, y+9, x+9, y+5);
    break;
  case 2:
    SDL_RenderDrawLine(sdlRender, x, y, x+5, y+9);
    SDL_RenderDrawLine(sdlRender, x+9, y, x+5, y+9);
    break;
  case 3:
    SDL_RenderDrawLine(sdlRender, x, y+5, x+9, y);
    SDL_RenderDrawLine(sdlRender, x, y+5, x+9, y+9);
    break;
  default:
    break;
  }
}

extern "C" void init(int x, int y) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize. Error: " << SDL_GetError() << std::endl;
  } else {
    win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x * 10, y * 10, SDL_WINDOW_OPENGL);
    if (win == NULL) {
      std::cout << "SDL window could not initialize. Error: " << SDL_GetError() << std::endl;
    }
  }
  sdlRender = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

extern "C" void render(GameState* game) {
  std::list<SnakeSt*>::iterator it = game->snake.begin();

  SDL_RenderClear(sdlRender);
  SDL_SetRenderDrawColor(sdlRender, 0, 0, 0, 255);

  drawtTri((*it)->x*10, (*it)->y*10, (*it)->direction);
  it++;

  SDL_Rect rect;
  rect.w = 10;
  rect.h = 10;

  for (; it != game->snake.end(); it++) {
    rect.x = (*it)->x * 10;
    rect.y = (*it)->y * 10;
    if((*it)->x > -1)
    SDL_RenderDrawRect(sdlRender, &rect);
  }
  rect.x = game->food->x * 10;
  rect.y = game->food->y * 10;
  SDL_SetRenderDrawColor(sdlRender, 0, 225, 0, 255);
  SDL_RenderFillRect(sdlRender, &rect);
  
  SDL_SetRenderDrawColor(sdlRender, 255, 255, 255, 255);
  SDL_RenderPresent(sdlRender);
}

extern "C" void endGame() {

}

extern "C" void closeWindow() {
  std::cout << "Window Closed!" << std::endl;
  SDL_DestroyWindow(win);
  SDL_Quit();
}

extern "C" int getInput() {
  SDL_Event event;

  SDL_PollEvent( &event );
  if (event.type == SDL_KEYDOWN) {
    //* */std::cout << event.key.keysym.sym << std::endl;
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
      return(0);
      break;
    case SDLK_RIGHT:
      return(1);
      break;
    case SDLK_DOWN:
      return(2);
      break;
    case SDLK_LEFT:
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
  } else {
    return (-1);
  }
}