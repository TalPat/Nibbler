#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Entity.hpp"

class Snake: public Entity
{
private:
  int _direction;
public:
  Snake(/* args */);
  Snake(const Snake &obj);
  ~Snake();
  Snake& operator=(const Snake &obj);
};

#endif