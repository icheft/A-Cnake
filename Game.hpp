#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
// #include "Snake.hpp"
// #define SIZE 15
// #define W 60
// #define H 50
// #define WIDTH SIZE * W
// #define HEIGHT SIZE * H

using namespace sf;

const int SIZE = 15; // default: 15 --> Do not modify
const int W = 60, H = 50;
const int WIDTH = SIZE * W;
const int HEIGHT = SIZE * H;


RenderWindow window(VideoMode(WIDTH, HEIGHT), "A Cnake");
const int SNAKE_MAX_LEN = 100;
const int SNAKE_START_LEN = 4;

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

void Snake::init1()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = 5;
        y[i] = H / 2;
    }
    dir = right;
    len = SNAKE_START_LEN;
}
void Snake::init2()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = W - 5;
        y[i] = H / 2;
    }
    dir = left;
    len = SNAKE_START_LEN;
}

Snake s1;
Snake s2;


struct Fruit
{
    int x;
    int y;
};
Fruit f;
Fruit b;


void Tick()
{
    for(int i = s1.len; i > 0; i--)
    {
        s1.x[i] = s1.x[i - 1];
        s1.y[i] = s1.y[i - 1];
    }
    for(int i = s2.len; i > 0; i--)
    {
        s2.x[i] = s2.x[i - 1];
        s2.y[i] = s2.y[i - 1];
    }
    
    if(s1.dir == down) s1.y[0] += 1; // down
    if(s1.dir == left) s1.x[0] -= 1; // left
    if(s1.dir == right) s1.x[0] += 1; // right
    if(s1.dir == up) s1.y[0] -= 1; // up
    
    if(s2.dir == down) s2.y[0] += 1;
    if(s2.dir == left) s2.x[0] -= 1;
    if(s2.dir == right) s2.x[0] += 1;
    if(s2.dir == up) s2.y[0] -= 1;
    
    
    // eat
    if((s1.x[0] == f.x) && (s1.y[0] == f.y))
    {
        s1.len++;
        // generate new fruit
        f.x = rand() % W;
        f.y = rand() % H;
    }
    if((s2.x[0] == f.x) && (s2.y[0] == f.y))
    {
        s2.len++;
        // generate new fruit
        f.x = rand() % W;
        f.y = rand() % H;
    }
    // generate bomb
    static bool bomb_created = false;
    if(s1.bomb == true)
    {
        // static bool bomb_created = false;
        if (bomb_created == false)
        {
            b.x = s1.x[s1.len - 1];
            b.y = s1.y[s1.len - 1];
            // bomb_created = true;
        }
        s1.bomb = false;
    }
    if(s2.bomb == true)
    {
        if (bomb_created == false)
        {
            b.x = s2.x[s2.len - 1];
            b.y = s2.y[s2.len - 1];
            // bomb_created = true;
        }
        s2.bomb = false;
    }
    // collided with bomb
    if((s1.x[0] == b.x) && (s1.y[0] == b.y))
    {
        if(s1.len >=3)
            s1.len -= 3;
        else
            s1.len = 0;
        b.x = -1;
        b.y = -1;
        bomb_created = false;
    }
    if((s2.x[0] == b.x) && (s2.y[0] == b.y))
    {
        if(s2.len >=3)
            s2.len -= 3;
        else
            s2.len = 0;
        b.x = -1;
        b.y = -1;
        bomb_created = false;
    }
    // over map size
    if(s1.x[0] > W) s1.x[0] = 0;
    if(s1.x[0] < 0) s1.x[0] = W;
    if(s1.y[0] > H) s1.y[0] = 0;
    if(s1.y[0] < 0) s1.y[0] = H;
    
    if(s2.x[0] > W) s2.x[0] = 0;
    if(s2.x[0] < 0) s2.x[0] = W;
    if(s2.y[0] > H) s2.y[0] = 0;
    if(s2.y[0] < 0) s2.y[0] = H;
    
    // self-collision
    for(int i = 1; i < s1.len; i++)
        if(s1.x[0] == s1.x[i] && s1.y[0] == s1.y[i])
            s1.len = 0;
    for(int i = 1; i < s2.len; i++)
        if(s2.x[0] == s2.x[i] && s2.y[0] == s2.y[i])
            s2.len = 0;
    // mutual collision
    for(int i = 1; i < s2.len; i++)
        if(s1.x[0] == s2.x[i] && s1.y[0] == s2.y[i])
            s1.len = 0;
    for(int i = 1; i < s1.len; i++)
        if(s2.x[0] == s1.x[i] && s2.y[0] == s1.y[i])
            s2.len = 0;
    // 頭撞頭
    if(s1.x[0] == s2.x[0] && s1.y[0] == s2.y[0])
    {
        // 相撞
        if( (s1.dir == 1 && s2.dir == 2) || (s1.dir == 2 && s2.dir == 1) || (s1.dir == 3 && s2.dir == 0) || (s1.dir == 0 && s2.dir == 3))
        {
            if(s1.len > s2.len) s2.len = 0;
            else if (s1.len < s2.len) s1.len = 0;
            else
            {
                // 平手
                s1.len = 0;
                s2.len = 0;
            }
        }
        // 側面撞頭
        else
        {
            s1.len = 0;
            s2.len = 0;
        }
    }
}

void run()
{
    Texture texture_background, texture_player1, texture_player2, texture_fruit, texture_bomb;
    texture_background.loadFromFile("resources/images/grass.png");
    texture_player1.loadFromFile("resources/images/blue.png");
    texture_player2.loadFromFile("resources/images/yellow.png");
    texture_fruit.loadFromFile("resources/images/potion.png");
    texture_bomb.loadFromFile("resources/images/bomb.png");
    
    Sprite background(texture_background);
    Sprite player1(texture_player1);
    Sprite player2(texture_player2);
    Sprite fruit(texture_fruit);
    Sprite bomb(texture_bomb);
    
    Clock clock;
    float timer = 0, delay = 0.07; // adjusting delay will affect the speed // default = 0.07
    f.x = 10;
    f.y = 10;
    b.x = -1;
    b.y = -1;
    s1.bomb = false;
    s2.bomb = false;
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
                window.close();
            
        }
        
        // should be modified
        if(Keyboard::isKeyPressed(Keyboard::Left))
            if(s1.dir != right) s1.dir = left;
        if(Keyboard::isKeyPressed(Keyboard::Right))
            if(s1.dir != left) s1.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::Up))
            if(s1.dir != down) s1.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::Down))
            if(s1.dir != up) s1.dir = down;
        
        
        if(Keyboard::isKeyPressed(Keyboard::A))
            if(s2.dir != right) s2.dir = left;
        if(Keyboard::isKeyPressed(Keyboard::D))
            if(s2.dir != left) s2.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::W))
            if(s2.dir != down) s2.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::S))
            if(s2.dir != up) s2.dir = down;
        
        //place bomb
        if(b.x == -1 && b.y == -1)
        {
            if(Keyboard::isKeyPressed(Keyboard::L))
                s1.bomb = true;
            if(Keyboard::isKeyPressed(Keyboard::Z))
                s2.bomb = true;
        }
        // ===== until here =====
        bool pause = false;
        if(Keyboard::isKeyPressed(Keyboard::Return)) pause = true;
            
        
        if(timer > delay)
        {
            timer = 0;
            Tick();
        }
        
        window.clear();
        for(int i = 0; i < W; i++)
        {
            for(int j = 0; j < H; j++)
            {
                background.setPosition(i * SIZE, j * SIZE);
                window.draw(background);
            }
        }
        for(int i = 0; i < s1.len; i++)
        {
            player1.setPosition(s1.x[i] * SIZE, s1.y[i] * SIZE);
            window.draw(player1);
        }
        
        for(int i = 0; i < s2.len; i++)
        {
            player2.setPosition(s2.x[i] * SIZE, s2.y[i] * SIZE);
            window.draw(player2);
        }
        
        // fruit color
        fruit.setPosition(f.x * SIZE,  f.y * SIZE);
        window.draw(fruit);
        // draw bomb
        bomb.setPosition(b.x * SIZE, b.y * SIZE);
        window.draw(bomb);
        
        while (pause)
        {
            if(timer > delay)
            {
                timer = 0;
                static int cnt = 1;
                std::cout << "Game paused " << cnt++ << std::endl;
                if(Keyboard::isKeyPressed(Keyboard::Return)) {
                    pause = false;
                    break;
                }
            }
            time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
        }
        window.display();
    }
}
