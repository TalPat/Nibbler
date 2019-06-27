#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>

struct SnakeSt
{
    int x, y, direction;
};

struct FoodSt
{
    int x, y;
};

struct GameState
{
    int score;
    std::list<SnakeSt*> snake;
    FoodSt* food;
};

#endif
