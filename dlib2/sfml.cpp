#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RenderWindow* win;

extern "C" void init(int x, int y) {
  win = new sf::RenderWindow(sf::VideoMode(x*10, y*10), "SFML Nibbler");
}

void drawtTri(int x, int y, int dir, sf::Color col) {
  sf::CircleShape triangle(5, 3);
  triangle.setFillColor(col);
  switch (dir)
  {
  case 0:
    triangle.setPosition(x*10, y*10);
    break;
  case 1:
    triangle.rotate(90.0f);
    triangle.setPosition((x+1)*10, y*10);
    break;
  case 2:
    triangle.rotate(180.0f);
    triangle.setPosition((x+1)*10, (y+1)*10);
    break;
  case 3:
    triangle.rotate(270.0f);
    triangle.setPosition(x*10, (y+1)*10);
    break;
  default:
    break;
  }
  win->draw(triangle);
}

extern "C" void render(GameState* game) {
  std::list<SnakeSt*>::iterator it = game->snake.begin();

  win->clear();

  drawtTri((*it)->x, (*it)->y, (*it)->direction, sf::Color::White);
  it++;

  sf::RectangleShape rectangle(sf::Vector2f(10, 10));

  for (; it != game->snake.end(); it++) {
    rectangle.setPosition((*it)->x*10, (*it)->y*10);
    if((*it)->x > -1)
      win->draw(rectangle);
      drawtTri((*it)->x, (*it)->y, (*it)->direction, sf::Color::Red);
  }
  rectangle.setPosition(game->food->x*10, game->food->y*10);
  rectangle.setFillColor(sf::Color::Green);
  win->draw(rectangle);
  
  win->display();

}

extern "C" void endGame() {
}

extern "C" void closeWindow() {
  delete win;
}

extern "C" int getInput() {
  sf::Event event;

  win->pollEvent(event);
  if (event.type == sf::Event::KeyPressed) {
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
      return(0);
      break;
    case sf::Keyboard::Right:
      return(1);
      break;
    case sf::Keyboard::Down:
      return(2);
      break;
    case sf::Keyboard::Left:
      return(3);
      break;
    case sf::Keyboard::Q:
      return(4);
      break;
    case sf::Keyboard::Space:
      return(5);
      break;
    case sf::Keyboard::Num1:
      return(6);
      break;
    case sf::Keyboard::Num2:
      return(7);
      break;
    case sf::Keyboard::Num3:
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