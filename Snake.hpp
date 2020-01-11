#pragma once
#include "Config.hpp"

struct Snake
{
    int x[SNAKE_MAX_LEN];
    int y[SNAKE_MAX_LEN];
    int dir;
    int len;
    void init1();
    void init2();
    bool bomb;
};