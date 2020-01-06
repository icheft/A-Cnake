#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
const int W = 60, H = 50; // 60, 50
const int WIDTH = SIZE * W;
const int HEIGHT = SIZE * H;



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

Snake s1;
Snake s2;


struct Water
{
    int x[25];
    int y[25];
    void init();
};
Water w;

void Water::init()
{
    for(int i = 0;i < 25;i++)
    {
        if(i < 5)
        {
            x[i] = 28 + i;
            y[i] = 23;
        }
        else if(i >= 5 && i < 10)
        {
            x[i] = 23 + i;
            y[i] = 24;
        }
        else if(i >= 10 && i < 15)
        {
            x[i] = 18 + i;
            y[i] = 25;
        }
        else if(i >= 15 && i < 20)
        {
            x[i] = 13 + i;
            y[i] = 26;
        }
        else if(i >= 20 && i < 25)
        {
            x[i] = 8 + i;
            y[i] = 27;
        }
    }
}


struct Fruit
{
    int x[3];
    int y[3];
    void init();
};
Fruit f;

void Fruit::init()
{
    x[0] = 10;
    y[0] = 14;
    x[1] = 20;
    y[1] = 27;
    x[2] = 30;
    y[2] = 5;
}

struct Fruit2
{
    int x[2];
    int y[2];
    void init();
};
Fruit2 f2;

void Fruit2::init()
{
    x[0] = 15;
    y[0] = 35;
    x[1] = 31;
    y[1] = 40;
}

struct Fruit3
{
    int x;
    int y;
    void init();
};
Fruit3 f3;

void Fruit3::init()
{
    x = 4;
    y = 30;
}

struct Bomb
{
    int x[300];
    int y[300];
    int index;
    void init();
};
Bomb b;

void Bomb::init()
{
    for(int i = 0;i < 300;i++)
    {
        x[i] = -1;
        y[i] = -1;
    }
    index = 0;
}

struct Brick
{
    int x[36];
    int y[36];
    void init();
};
Brick br;

void Brick::init()
{
    for(int i = 0; i < 36;i++)
    {
        if(i < 5)
        {
            x[i] = 7 + i;
            y[i] = 7;
        }
        else if (i >= 5 && i < 10)
        {
            x[i] = 44 + i;
            y[i] = 7;
        }
        else if (i >= 10 && i < 15)
        {
            x[i] = -3 + i;
            y[i] = 43;
        }
        else if (i >= 15 && i < 20)
        {
            x[i] = 34 + i;
            y[i] = 43;
        }
        else if (i >= 20 && i < 24)
        {
            x[i] = 7;
            y[i] = -12 + i;
        }
        else if (i >= 24 && i < 28)
        {
            x[i] = 7;
            y[i] = 15 + i;
        }
        else if (i >= 28 && i < 32)
        {
            x[i] = 53;
            y[i] = -20 + i;
        }
        else if (i >= 32 && i < 36)
        {
            x[i] = 53;
            y[i] = 7 + i;
        }
    }
}


void Tick()
{
    static int tickCnt = 0;
    static SoundBuffer b1, b2, b3, b4, b5, b6, b7, b8;
    static Sound explosion, wallHit, drink1, drink2, drink3, potionCreated, water, collision;
    if (tickCnt == 0)
    {
        if (!b1.loadFromFile("resources/audio/explode.wav")) return;
        explosion.setVolume(50);
        explosion.setBuffer(b1);
        if (!b2.loadFromFile("resources/audio/wall-hit.wav")) return;
        wallHit.setVolume(50);
        wallHit.setBuffer(b2);

        if (!b3.loadFromFile("resources/audio/potion-drinking.wav")) return;
        potionCreated.setVolume(50);
        potionCreated.setBuffer(b3);
        if (!b4.loadFromFile("resources/audio/water.wav")) return;
        water.setVolume(90);
        water.setBuffer(b4);
        if (!b5.loadFromFile("resources/audio/collision.wav")) return;
        collision.setVolume(90);
        collision.setBuffer(b5);
        if (!b6.loadFromFile("resources/audio/drink1.wav")) return;
        drink1.setVolume(90);
        drink1.setBuffer(b6);
        if (!b7.loadFromFile("resources/audio/drink2.wav")) return;
        drink2.setVolume(90);
        drink2.setBuffer(b7);
        if (!b8.loadFromFile("resources/audio/drink3.wav")) return;
        drink3.setVolume(90);
        drink3.setBuffer(b8);
        

        

        tickCnt++;
    }
    
    
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
    
    
    // eat fruit
    for (int j = 0;j < 3;j++)
    {
        if((s1.x[0] == f.x[j]) && (s1.y[0] == f.y[j]))
        {
            s1.len++;
            drink1.play();
            // generate new fruit
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f.x[j] = rand() % W;
                f.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f.x[j] == b.x[i] && f.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f.x[j] == br.x[i] && f.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f.x[j] == w.x[i] && f.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    for (int j = 0;j < 3;j++)
    {
        if((s2.x[0] == f.x[j]) && (s2.y[0] == f.y[j]))
        {
            s2.len++;
            drink1.play();
            // generate new fruit
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f.x[j] = rand() % W;
                f.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f.x[j] == b.x[i] && f.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f.x[j] == br.x[i] && f.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f.x[j] == w.x[i] && f.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    // eat fruit2
    for (int j = 0;j < 2;j++)
    {
        if((s1.x[0] == f2.x[j]) && (s1.y[0] == f2.y[j]))
        {
            s1.len++;
            drink2.play();
            // generate new fruit
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f2.x[j] = rand() % W;
                f2.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f2.x[j] == b.x[i] && f2.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f2.x[j] == br.x[i] && f2.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f2.x[j] == w.x[i] && f2.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    for (int j = 0;j < 2;j++)
    {
        if((s2.x[0] == f2.x[j]) && (s2.y[0] == f2.y[j]))
        {
            s2.len++;
            drink2.play();
            // generate new fruit2
            bool overlap = true;
            while(overlap)
            {
                bool flag = false;
                f2.x[j] = rand() % W;
                f2.y[j] = rand() % H;
                for (int i = 0; i < 300;i++)
                {
                    if (f2.x[j] == b.x[i] && f2.y[j] == b.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 36;i++)
                {
                    if (f2.x[j] == br.x[i] && f2.y[j] == br.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                for (int i = 0; i < 25;i++)
                {
                    if (f2.x[j] == w.x[i] && f2.y[j] == w.y[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    overlap = false;
                }
            }
        }
    }
    // eat fruit3
    if((s1.x[0] == f3.x) && (s1.y[0] == f3.y))
    {
        s1.len++;drink3.play();
        // generate new fruit3
        bool overlap = true;
        while(overlap)
        {
            bool flag = false;
            f3.x = rand() % W;
            f3.y = rand() % H;
            for (int i = 0; i < 300;i++)
            {
                if (f3.x == b.x[i] && f3.y == b.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 36;i++)
            {
                if (f3.x == br.x[i] && f3.y == br.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 25;i++)
            {
                if (f3.x == w.x[i] && f3.y == w.y[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                overlap = false;
            }
        }
    }
    if((s2.x[0] == f3.x) && (s2.y[0] == f3.y))
    {
        s2.len++;
        drink3.play();
        // generate new fruit3
        bool overlap = true;
        while(overlap)
        {
            bool flag = false;
            f3.x = rand() % W;
            f3.y = rand() % H;
            for (int i = 0; i < 300;i++)
            {
                if (f3.x == b.x[i] && f3.y == b.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 36;i++)
            {
                if (f3.x == br.x[i] && f3.y == br.y[i])
                {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < 25;i++)
            {
                if (f3.x == w.x[i] && f3.y == w.y[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                overlap = false;
            }
        }
    }
//    if((s2.x[0] == f.x) && (s2.y[0] == f.y))
//    {
//        s2.len++;
//        // generate new fruit
//        f.x = rand() % W;
//        f.y = rand() % H;
//    }
    // generate bomb from snake's bottom
    static bool bomb_created = false;
    if(s1.bomb == true)
    {
        // static bool bomb_created = false;
        if (bomb_created == false && s1.len > 1)
        {
            b.x[b.index] = s1.x[s1.len - 1];
            b.y[b.index] = s1.y[s1.len - 1];
            b.index++;
//            bomb_created = true;
        }
        s1.bomb = false;
    }
    if(s2.bomb == true)
    {
        // static bool bomb_created = false;
        if (bomb_created == false && s2.len > 1)
        {
            b.x[b.index] = s2.x[s2.len - 1];
            b.y[b.index] = s2.y[s2.len - 1];
            b.index++;
            //            bomb_created = true;
        }
        s2.bomb = false;
    }
    // generate random bomb
//    if(s1.bomb == true)
//    {
//        b.x[b.index] = rand() % W;
//        b.y[b.index] = rand() % H;
//        b.index++;
//        s1.bomb = false;
//    }
//    if(s2.bomb == true)
//    {
//        b.x[b.index] = rand() % W;
//        b.y[b.index] = rand() % H;
//        b.index++;
//        s2.bomb = false;
//    }
    // collided with bomb
    for (int i = 0;i < b.index;i++)
    {
        if((s1.x[0] == b.x[i]) && (s1.y[0] == b.y[i]))
        {
            if(s1.len >=3)
                s1.len -= 3;
            else
                s1.len = 0;
            b.x[i] = -1;
            b.y[i] = -1;
            bomb_created = false;
            explosion.play();
        }
    }
    for (int i = 0;i < b.index;i++)
    {
        if((s2.x[0] == b.x[i]) && (s2.y[0] == b.y[i]))
        {
            if(s2.len >=3)
                s2.len -= 3;
            else
                s2.len = 0;
            b.x[i] = -1;
            b.y[i] = -1;
            bomb_created = false;
            explosion.play();
        }
    }
    // collided with water
    for(int i = 0; i < 25 ;i++)
    {
        // if((s1.len > 2) && (s1.x[0] == w.x[i]) && (s1.y[0] == w.y[i]) && (s1.x[1] == w.x[i]) && (s1.y[1] == w.y[i]) && (s1.x[2] == w.y[i]) && (s1.y[2] == w.y[i]))
        // {
        //     s1.len = 0;
        // }
        /* else */ if ((s1.x[0] == w.x[i]) && (s1.y[0] == w.y[i])) 
        {
            s1.len = 0;
            water.play();
            // collision.setVolume(20);
        }
    }
    for(int i = 0;i < 25;i++)
    {
        if((s2.x[0] == w.x[i]) && (s2.y[0] == w.y[i]))
        {
            s2.len = 0;
            water.play(); 
            // collision.setVolume(20);
        }
    }
    // collided with brick
    for(int i = 0;i < 36;i++)
    {
        if((s1.x[0] == br.x[i]) && (s1.y[0] == br.y[i]))
        {
            s1.len = 0;
            wallHit.play();
        }
    }
    for(int i = 0;i < 36;i++)
    {
        if((s2.x[0] == br.x[i]) && (s2.y[0] == br.y[i]))
        {
            s2.len = 0;
            wallHit.play();
        }
    }
    // over map size
    if(s1.x[0] >= W) s1.x[0] = 0;
    if(s1.x[0] < 0) s1.x[0] = W - 1;
    if(s1.y[0] >= H) s1.y[0] = 0;
    if(s1.y[0] < 0) s1.y[0] = H - 1;
    
    if(s2.x[0] >= W) s2.x[0] = 0;
    if(s2.x[0] < 0) s2.x[0] = W - 1;
    if(s2.y[0] >= H) s2.y[0] = 0;
    if(s2.y[0] < 0) s2.y[0] = H - 1;
    
    // self-collision
    for(int i = 1; i < s1.len; i++)
        if(s1.x[0] == s1.x[i] && s1.y[0] == s1.y[i])
            {
                s1.len = 0;
                collision.play();
            }
    for(int i = 1; i < s2.len; i++)
        if(s2.x[0] == s2.x[i] && s2.y[0] == s2.y[i])
            {
                s2.len = 0;
                collision.play();
            }
    // mutual collision
    for(int i = 1; i < s2.len; i++)
        if(s1.x[0] == s2.x[i] && s1.y[0] == s2.y[i])
            {
                s1.len = 0;
                collision.play();
            }
    for(int i = 1; i < s1.len; i++)
        if(s2.x[0] == s1.x[i] && s2.y[0] == s1.y[i])
            {
                s2.len = 0;
                collision.play();
            }
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
                collision.play();
            }
        }
        // 側面撞頭
        else
        {
            s1.len = 0;
            s2.len = 0;
            collision.play();
        }
    }
}

int check(Snake s1, Snake s2)
{
    int playerID = 0;
    if (s1.len == 0 && s2.len == 0) return playerID = 3;
    else if (s2.len == 0) return playerID = 1;
    else if (s1.len == 0) return playerID = 2;
    else return playerID;

}

void dead(int playerID, RenderWindow &window)
{
    SoundBuffer buffer;
     if (!buffer.loadFromFile("resources/audio/cheering.wav")) return;

    Sound cheer;
    cheer.setVolume(50);
    cheer.setBuffer(buffer);
    cheer.play();
    Texture texture_p1win, texture_p2win, texture_tie;
    texture_p1win.loadFromFile("resources/images/player1wins.png");
    texture_p2win.loadFromFile("resources/images/player2wins.png");
    texture_tie.loadFromFile("resources/images/tie.png");

    Sprite p1(texture_p1win);
    Sprite p2(texture_p2win);
    Sprite tie(texture_tie);
    // Event event;
    // Text title;
    // Font font;
    // if (!font.loadFromFile("resources/fonts/prstartk.ttf"))
    // {
    //     // handle error
    // }
    // title.setFont(font);
    // title.setColor(Color(255, 211, 92, 250));
    // // title.setString("A CNAKE");
    // title.setCharacterSize(60);
    // // title.setScale(Vector2f(2, 2));
    // title.setPosition(Vector2f(WIDTH / 2 - 270, HEIGHT / 2 - 100));

    // window.clear(Color(128, 124, 115, 255));
    
    // if (playerID == 1) {
    //     title.setString("Player 1\n\n Wins!");
    // }
    // else if (playerID == 2) {
    //     title.setString("Player 2\n\n Wins!");
    // }
    // else if (playerID == 3){
    //     title.setString("Fair\n\n Play!");
    // }
    if (playerID == 1) window.draw(p1);
    else if (playerID == 2) window.draw(p2);
    else if (playerID == 3) window.draw(tie);
    // window.draw(title);
    
    window.display();
    Clock clock;
    float timer = 0, limit = 1.5;
    while (timer < limit)
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
    }
    // if (window.close();
    
}

void run()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A CNAKE");
    s1.init1();
    s2.init2();
    b.init();
    f.init();
    br.init();
    f2.init();
    f3.init();
    w.init();

    Texture texture_background, texture_player1, texture_player2, texture_fruit, texture_bomb, texture_brick, texture_fruit2, texture_fruit3, texture_water;
    texture_background.loadFromFile("resources/images/grass.png");
    texture_player1.loadFromFile("resources/images/blue.png");
    texture_player2.loadFromFile("resources/images/yellow.png");
    texture_fruit.loadFromFile("resources/images/purple-potion.png");
    texture_bomb.loadFromFile("resources/images/bomb.png");
    texture_brick.loadFromFile("resources/images/brick.png");
    texture_fruit2.loadFromFile("resources/images/white-potion.png");
    texture_fruit3.loadFromFile("resources/images/pink-potion.png");
    texture_water.loadFromFile("resources/images/water.png");
    
    Sprite background(texture_background);
    Sprite player1(texture_player1);
    Sprite player2(texture_player2);
    Sprite fruit(texture_fruit);
    Sprite bomb(texture_bomb);
    Sprite brick(texture_brick);
    Sprite fruit2(texture_fruit2);
    Sprite fruit3(texture_fruit3);
    Sprite water(texture_water);
    
    Clock clock;
    float timer = 0, delay = 0.07; // adjusting delay will affect the speed // default = 0.07
    s1.bomb = false;
    s2.bomb = false;
    SoundBuffer buffer;
    if (!buffer.loadFromFile("resources/audio/bomb-planted.wav")) return;
    Sound bombPlanted;
    bombPlanted.setVolume(50);
    bombPlanted.setBuffer(buffer);
    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("resources/audio/pop.wav")) 
        return;
    Sound pop;
    pop.setVolume(50);
    pop.setBuffer(buffer2);


    
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
        {if(s1.dir != right) s1.dir = left;}
        else if(Keyboard::isKeyPressed(Keyboard::Right))
            if(s1.dir != left) s1.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::Up))
            if(s1.dir != down) s1.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::Down))
            if(s1.dir != up) s1.dir = down;
        
        
        if(Keyboard::isKeyPressed(Keyboard::A))
            {if(s2.dir != right) s2.dir = left;}
        else if(Keyboard::isKeyPressed(Keyboard::D))
            if(s2.dir != left) s2.dir = right;
        if(Keyboard::isKeyPressed(Keyboard::W))
            if(s2.dir != down) s2.dir = up;
        if(Keyboard::isKeyPressed(Keyboard::S))
            if(s2.dir != up) s2.dir = down;
        
        //place bomb
        
        if(Keyboard::isKeyPressed(Keyboard::L))
            if(b.x[b.index] == -1 && b.y[b.index] == -1)
            {
                bombPlanted.play();
                s1.bomb = true;
            }
                
        if(Keyboard::isKeyPressed(Keyboard::LShift))
            if(b.x[b.index] == -1 && b.y[b.index] == -1)
            {
                bombPlanted.play();
                s2.bomb = true;
            }
        // ===== until here =====
        bool pause = false;
        if(Keyboard::isKeyPressed(Keyboard::BackSpace)) {
            pause = true;
            pop.play();
        }
            
        int checkFlag = check(s1, s2);
        if(timer > delay)
        {
            timer = 0;
            Tick();
            if (checkFlag)
            {
                dead(checkFlag, window);
                window.close();
                // window.close();
            }
            // if (checkFlag == 1) {
            //     std::cout << "Blue wins" << std::endl;
            //     dead(checkFlag);
            //     pause = true;
            // }
            // else if (checkFlag == 2) {
            //     std::cout << "Yellow wins" << std::endl;
            //     dead(checkFlag);
            //     pause = true;
            // }
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
        
        //draw water
        for (int i = 0;i < 25;i++)
        {
            water.setPosition(w.x[i] * SIZE,  w.y[i] * SIZE);
            window.draw(water);
        }
        // draw brick
        for (int i = 0;i < 36;i++)
        {
            brick.setPosition(br.x[i] * SIZE,  br.y[i] * SIZE);
            window.draw(brick);
        }
        // draw fruit
        for(int i = 0;i < 3;i++)
        {
            fruit.setPosition(f.x[i] * SIZE,  f.y[i] * SIZE);
            window.draw(fruit);
        }
        // draw fruit2
        for(int i = 0;i < 2;i++)
        {
            fruit2.setPosition(f2.x[i] * SIZE,  f2.y[i] * SIZE);
            window.draw(fruit2);
        }
        // draw fruit3
        fruit3.setPosition(f3.x * SIZE,  f3.y * SIZE);
        window.draw(fruit3);
        // draw bomb
        for (int i = 0;i < b.index;i++)
        {
            bomb.setPosition(b.x[i] * SIZE, b.y[i] * SIZE);
            window.draw(bomb);
        }
        
        
        while (pause)
        {
            static bool first_time = true;
            time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            static int cnt = 1;
            
            if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
                pause = false;
                pop.play();
            }
            if(timer > delay)
            {
                std::cout << "Game paused " << cnt++ << std::endl;
                timer = 0;
                if (pause == false) break;
            }

            // if (checkFlag && first_time) 
            // {
            //     delay += 5;
            //     first_time = false;
            // }
            // if (checkFlag && timer > delay) 
            // {   
            //     // std::cout << "Game ! " << cnt++ << std::endl;
            //     window.close();
            //     // if(checkFlag == 1) {
            //     //     window.close();
            //     // }
            //     // else if (checkFlag == 2) {
            //     //     window.close();
            //     // }
                    
            // }
            // if(timer > delay) timer = 0;
            
        }
        window.display();
    }
    // load image --> player whom wins
    // 

}
