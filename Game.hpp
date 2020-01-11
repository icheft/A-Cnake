#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Config.hpp"
#include <ctime>
#include <iostream>

using namespace sf;
// const int SIZE = 15; // default: 15 --> Do not modify
// const int W = 60, H = 50; // 60, 50
// const int WIDTH = SIZE * W;
// const int HEIGHT = SIZE * H;
// const int SNAKE_MAX_LEN = 100;
// const int SNAKE_START_LEN = 4;
enum direction {down, left, right, up};

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


class Game
{
private:
    Snake s1, s2;
    Water w;
    Portion_1stType f;
    Portion_2ndType f2;
    Portion_3rdType f3;
    Bomb b;
    Brick br;
public:
    Game(); // init
    ~Game();
    void tick();
    int check(Snake s1, Snake s2);
    void dead(int playerID, RenderWindow &window);
    void run();
};
