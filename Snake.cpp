#include "Snake.hpp"
enum direction {down, left, right, up};

Snake::Snake(int playerID)
{
    x = new int[this->SNAKE_MAX_LEN];
    y = new int[this->SNAKE_MAX_LEN];
    if (playerID == 1)
    {
        for(int i = 0; i < this->SNAKE_MAX_LEN; i++)
        {
            this->x[i] = 5;
            this->y[i] = H / 2;
        }
        this->dir = right;
        this->len = SNAKE_START_LEN;
    }
    else if (playerID == 2)
    {
        for(int i = 0; i < this->SNAKE_MAX_LEN; i++)
        {
            this->x[i] = W - 5;
            this->y[i] = H / 2;
        }
        this->dir = left;
        this->len = SNAKE_START_LEN;
    }
}

// void Snake::init1()
// {
    
// }
// void Snake::init2()
// {
//     for(int i = 0; i < SNAKE_MAX_LEN; i++)
//     {
//         x[i] = W - 5;
//         y[i] = H / 2;
//     }
//     dir = left;
//     len = SNAKE_START_LEN;
// }