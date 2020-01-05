#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"
#include <ctime>
using namespace sf;

// const int SIZE = 15; // default: 15 --> Do not modify
// const int W = 60, H = 50;
// const int WIDTH = SIZE * W;
// const int HEIGHT = SIZE * H;




int main()
{
    
    // setting
    srand(time(0));
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A Cnake");

    Menu menu(window.getSize().x, window.getSize().y);
    


    while(window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch(event.key.code)
                {
                    case Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case Keyboard::Down:
                        menu.MoveDown();
                        break;
                    case Keyboard::Return:
                        switch(menu.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Play button has been pressed" << std::endl;
                            window.close();
                            run();
                            break;
                        case 1:
                            std::cout << "Setting button has been pressed" << std::endl;
                            // to be modified
                            break;
                        case 2:
                            window.close();
                            break;
                        }
                        break;
                }
                break;
            case Event::Closed:
                window.close();

                break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
        
    }
    return 0;
}




