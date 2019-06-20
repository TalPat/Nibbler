#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Entity.hpp"

class Snake: public Entity
{
private:
  int _direction; // default to 0(up). 1(right). 2(down). 3(left)
public:
  Snake(int x, int y);
  Snake(const Snake &obj);
  ~Snake();
  Snake& operator=(const Snake &obj);
};

#endif