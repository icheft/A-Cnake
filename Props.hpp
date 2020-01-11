#pragma once
#include "Config.hpp"

struct Water
{
    int x[25];
    int y[25];
    void init();
};


struct Portion_1stType
{
    int x[3];
    int y[3];
    void init();
};


struct Portion_2ndType
{
    int x[2];
    int y[2];
    void init();
};


struct Portion_3rdType
{
    int x;
    int y;
    void init();
};

struct Bomb
{
    int x[300];
    int y[300];
    int index;
    void init();
};

struct Brick
{
    int x[36];
    int y[36];
    void init();
};