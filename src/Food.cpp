#include "Food.hpp"

Food::Food(int x, int y):
Entity(x, y)
{
}

Food& Food::operator=(const Food &obj){
  if (this != &obj) {
    this->setPosx(obj.getPosx());
    this->setPosy(obj.getPosy());
  }
  return (*this);
}

Food::~Food()
{
}
