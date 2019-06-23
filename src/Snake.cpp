#include "Snake.hpp"
#include "Entity.hpp"

Snake::Snake(int x, int y):
Entity(x, y)
{
  this->_direction = 0;
}

Snake& Snake::operator=(const Snake &obj){
  if (this != &obj) {
    this->setPosx(obj.getPosx());
    this->setPosy(obj.getPosy());
    this->_direction = obj._direction;
  }
  return (*this);
}

Snake::~Snake()
{
}

void Snake::setDirection(int direction){
  this->_direction = direction;
}

int Snake::getDirection(void) const{
  return (this->_direction);
}
