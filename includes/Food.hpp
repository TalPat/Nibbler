#ifndef FOOD_HPP
#define FOOD_HPP

#include "Entity.hpp"

class Food: public Entity
{
private:
  /* data */
public:
  Food(int x, int y);
  Food(const Food &obj);
  ~Food();
  Food& operator=(const Food &obj);
};

#endif
