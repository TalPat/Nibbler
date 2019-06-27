#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>

struct FoodSt
{
    int x, y;
};

struct SnakeSt
{
    int x, y, direction;
};


struct GameState
{
    int score;
    std::list<SnakeSt*> snake;
    FoodSt* food;
};

#endif
