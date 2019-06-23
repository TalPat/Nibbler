#include "Entity.hpp"

Entity::Entity(int x, int y)
{
  this->_posx = x;
  this->_posy = y;
}

Entity& Entity::operator=(const Entity &obj){
  if (this != &obj) {
    this->_posx = obj._posx;
    this->_posy = obj._posy;
  }
  return (*this);
}

Entity::~Entity()
{
}

int Entity::getPosx(void) const{
  return (this->_posx);
}

int Entity::getPosy(void) const{
  return (this->_posy);
}

void Entity::setPosx(int posx){
  this->_posx = posx;
}
void Entity::setPosy(int posy){
  this->_posy = posy;
}