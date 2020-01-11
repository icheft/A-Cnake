#include "Snake.hpp"

void Snake::init1()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = W - 5;
        y[i] = H / 2 + 4;
    }
    dir = left;
    len = SNAKE_START_LEN;
}

void Snake::init2()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = 5;
        y[i] = H / 2 - 4;
    }
    dir = right;
    len = SNAKE_START_LEN;
}
