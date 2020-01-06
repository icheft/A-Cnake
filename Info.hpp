#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

#define MAX_NUM_OF_PAGES 2

class Info
{
private:

    int selectedPageIndex;
    // Font font;
    // Text pages[MAX_NUM_OF_PAGES];
    Texture pages_texture[MAX_NUM_OF_PAGES];
    Sprite pages[MAX_NUM_OF_PAGES];
    // Text title;

public:
    Info(float width, float height);
    ~Info();
    void info_state();

    void draw(RenderWindow &window, Sprite &page);
    int prevPage();
    int nextPage();
    // int loadFile() {return selectedPageIndex;};

};

