#include "Info.hpp"


Info::Info(float width, float height)
{
    // if (!font.loadFromFile("resources/fonts/prstartk.ttf"))
    // {
    //     // handle error
    // }

    if (!pages_texture[0].loadFromFile("resources/images/player1wins.png"))
    {
        // handle error
    }
    if (!pages_texture[1].loadFromFile("resources/images/player2wins.png"))
    {
        // handle error
    }

    pages[0].setTexture(pages_texture[0]);
    pages[1].setTexture(pages_texture[1]);
    /*

    Sprite p1(texture_p1win);
    Sprite p2(texture_p2win);
    Sprite tie(texture_tie);
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
    
    */
    // pages[0].setFont(font);
    // pages[0].setColor(Color(254, 255, 212, 255));
    // pages[0].setString("Play");
    // pages[0].setPosition(Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 2) * 2));

    // pages[].setFont(font);
    // pages[].setColor(Color(255, 255, 255, 180));
    // pages[].setString("Settings");
    // pages[].setPosition(Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    // pages[1].setFont(font);
    // pages[1].setColor(Color(255, 255, 255, 180));
    // pages[1].setString("Quit");
    // pages[1].setPosition(Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 2) * 3 - 100));

    selectedPageIndex = 0;
}

Info::~Info()
{
}

void Info::info_state()
{
    const int SIZE = 15; // default: 15 --> Do not modify
    const int W = 60, H = 50; // 60, 50
    const int WIDTH = SIZE * W;
    const int HEIGHT = SIZE * H;
    SoundBuffer buffer;
    if (!buffer.loadFromFile("resources/audio/pop.wav")) 
        return;
    Sound pop;
    pop.setVolume(50);
    pop.setBuffer(buffer);
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A Cnake");

    while(window.isOpen())
    {
        Event event;
        int pageIndex = 0;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch(event.key.code)
                {
                    case Keyboard::Left:
                        window.clear();
                        pop.play();
                        pageIndex = prevPage();
                        break;
                    case Keyboard::Right:
                        pop.play();
                        pageIndex = nextPage();
                        break;
                    case Keyboard::Space:
                        window.close();
                        break;
                }
                break;
            case Event::Closed:
                window.close();
                break;
            }
            window.clear();
            draw(window, pages[pageIndex]);
            window.display();
    }
    
    window.display();
    
    }
}

void Info::draw(RenderWindow &window, Sprite &page)
{
    // window.clear();
    window.draw(page);
    
    // for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    // {
    //     window.draw(pages[i]);
    // }
}

int Info::prevPage()
{
    if (selectedPageIndex - 1 >= 0)
    {
        return (--selectedPageIndex);
    }
    else return selectedPageIndex;
}

int Info::nextPage()
{
    if (selectedPageIndex + 1 < MAX_NUM_OF_PAGES)
    {
        // pages[selectedItemIndex].setColor(Color(255, 255, 255, 180));
        // selectedItemIndex++;
        // pages[selectedItemIndex].setColor(Color(254, 255, 212, 255));
        return (++selectedPageIndex);
    }
    else return selectedPageIndex;
}