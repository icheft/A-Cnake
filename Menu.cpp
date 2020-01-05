#include "Menu.hpp"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("resources/fonts/cute-pixel.ttf"))
    {
        // handle error
    }
    menu[0].setFont(font);
    menu[0].setColor(Color(254, 255, 212, 255));
    menu[0].setString("Play");
    menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(Color(255, 255, 255, 180));
    menu[1].setString("Settings");
    menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(Color(255, 255, 255, 180));
    menu[2].setString("Quit");
    menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
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