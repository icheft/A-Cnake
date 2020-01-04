#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

const int SIZE = 15;
const int W = 60, H = 50;
const int WIDTH = SIZE * W;
const int HEIGHT = SIZE * H;
const int SNAKE_MAX_LEN = 100;
const int SNAKE_START_LEN = 4;

enum direction {up, left, right, down};

struct Snake
{
    int x[SNAKE_MAX_LEN];
    int y[SNAKE_MAX_LEN];
    int dir;
    int len;
    void init1();
    void init2();
};

void Snake::init1()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = 5;
        y[i] = H / 2;
    }
    dir = direction::right;
    len = SNAKE_START_LEN;
}
void Snake::init2()
{
    for(int i = 0; i < SNAKE_MAX_LEN; i++)
    {
        x[i] = W - 5;
        y[i] = H / 2;
    }
    dir = direction::left;
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
    
    if(s1.dir == 0) s1.y[0] += 1; // up 
    if(s1.dir == 1) s1.x[0] -= 1; // left
    if(s1.dir == 2) s1.x[0] += 1; // right
    if(s1.dir == 3) s1.y[0] -= 1; // down
    
    if(s2.dir == 0) s2.y[0] += 1;
    if(s2.dir == 1) s2.x[0] -= 1;
    if(s2.dir == 2) s2.x[0] += 1;
    if(s2.dir == 3) s2.y[0] -= 1;
    

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

int main()
{
    s1.init1();
    s2.init2();
    // setting
    srand(time(0));
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A Cnake");
    
    Texture texture_background, texture_player1, texture_player2, texture_fruit;
    texture_background.loadFromFile("images/all-dark-blue.png");
    texture_player1.loadFromFile("images/red.png");
    texture_player2.loadFromFile("images/green.png");
    texture_fruit.loadFromFile("images/yellow.png");
    
    Sprite background(texture_background);
    Sprite player1(texture_player1);
    Sprite player2(texture_player2);
    Sprite fruit(texture_fruit);
    
    Clock clock;
    float timer = 0, delay = 0.05; // adjusting delay will affect the speed
    f.x = 10;
    f.y = 10;
    
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
            if(s1.dir != 2)
            {
                s1.dir = 1;
            }
        if(Keyboard::isKeyPressed(Keyboard::Right))
            if(s1.dir != 1)
            {
                s1.dir = 2;
            }
        if(Keyboard::isKeyPressed(Keyboard::Up))
            if(s1.dir != 0)
            {
                s1.dir = 3;
            }
        if(Keyboard::isKeyPressed(Keyboard::Down))
            if(s1.dir != 3)
            {
                s1.dir = 0;
            }
        if(Keyboard::isKeyPressed(Keyboard::A))
            if(s2.dir != 2)
            {
                s2.dir = 1;
            }
        if(Keyboard::isKeyPressed(Keyboard::D))
            if(s2.dir != 1)
            {
                s2.dir = 2;
            }
        if(Keyboard::isKeyPressed(Keyboard::W))
            if(s2.dir != 0)
            {
                s2.dir = 3;
            }
        if(Keyboard::isKeyPressed(Keyboard::S))
            if(s2.dir != 3)
            {
                s2.dir = 0;
            }
        // ===== until here =====
        
        
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

        
        window.display();
    }
    return 0;
}




