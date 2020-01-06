#pragma once
#include "Game.hpp"
// #ifndef 
// /* code */
// #else
// /* code to include if the token is defined */
// #endif


class Snake
{
private:
    const int SNAKE_MAX_LEN = 100;
    const int SNAKE_START_LEN = 4;
    int *x;
    int *y;
    int dir;
    int len;
    // void init1();
    // void init2();
    bool bomb;
public:
    Snake(int playerID);
    ~Snake();
friend void Game::Tick();
};