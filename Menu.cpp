#include "Menu.hpp"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("resources/fonts/prstartk.ttf"))
    {
        // handle error
    }
    
    title.setFont(font);
    title.setColor(Color(255, 211, 92, 250));
    title.setString("A Cnake");
    title.setCharacterSize(60);
    // title.setScale(Vector2f(2, 2));
    title.setPosition(Vector2f(width / 2 - 200, height / (MAX_NUMBER_OF_ITEMS + 2) * 1));

    menu[0].setFont(font);
    menu[0].setColor(Color(254, 255, 212, 255));
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 2) * 2));

    menu[1].setFont(font);
    menu[1].setColor(Color(255, 255, 255, 180));
    menu[1].setString("Instructions");
    menu[1].setPosition(Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 2) * 3 - 100));
    menu[2].setFont(font);
    menu[2].setColor(Color(255, 255, 255, 180));
    menu[2].setString("Quit");
    menu[2].setPosition(Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 2) * 4 - 100));

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
    window.clear(Color(64, 75, 104, 255));
    window.draw(title);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(Color(255, 255, 255, 180));
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(Color(254, 255, 212, 255));
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(Color(255, 255, 255, 180));
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(Color(254, 255, 212, 255));
    }
}