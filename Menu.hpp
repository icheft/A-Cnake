#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
private:
    int selectedItemIndex;
    Font font;
    Text menu[MAX_NUMBER_OF_ITEMS];
    Text title;

public:
    Menu(float width, float height);
    ~Menu();

    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() {return selectedItemIndex;};

};

