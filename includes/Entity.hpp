#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{
private:
  int _posx, _posy;
public:
  Entity();
  Entity(int x, int y);
  Entity(const Entity &obj);
  ~Entity();
  Entity& operator=(const Entity &obj);

  int getPosx(void) const;
  int getPosy(void) const;

  void setPosx(int posx);
  void setPosy(int posy);
};

#endif
