#include <SFML/Audio.hpp>
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
    Image image;
    // setting
    srand(time(0));
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "A Cnake");

    Menu menu(window.getSize().x, window.getSize().y);
    Music music;
    if (!music.openFromFile("resources/audio/opening-funky.ogg"))
        return -1; // error
    music.setVolume(20);
    music.setLoop(true);
    music.play();
    
    SoundBuffer buffer;
    if (!buffer.loadFromFile("resources/audio/pop.wav")) 
        return -1;
    Sound pop;
    pop.setVolume(50);
    pop.setBuffer(buffer);
    SoundBuffer bLeave;
    if (!bLeave.loadFromFile("resources/audio/leave.wav")) 
        return -1;
    Sound leave;
    leave.setVolume(50);
    leave.setBuffer(bLeave);
    SoundBuffer bEnter;
    if (!bEnter.loadFromFile("resources/audio/enter.wav")) 
        return -1;
    Sound enter;
    enter.setVolume(50);
    enter.setBuffer(bEnter);

menuLabel:
    while(window.isOpen())
    {
        Event event;
        Clock clock;
        float timer = 0, limit = 0.3;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                switch(event.key.code)
                {
                    case Keyboard::Up:
                        menu.MoveUp();
                        pop.play();
                        break;
                    case Keyboard::Down:
                        menu.MoveDown();
                        pop.play();
                        break;
                    case Keyboard::Return:
                        switch(menu.GetPressedItem())
                        {
                        case 0:
                            std::cout << "Play button has been pressed" << std::endl;
                            music.setVolume(10);
                            window.setVisible(false);
                            enter.play();
                            while (timer < limit)
                            {
                                float time = clock.getElapsedTime().asSeconds();
                                clock.restart();
                                timer += time;
                            }
                            run();
                            music.setVolume(20);
                            window.setVisible(true);
                            break;
                        case 1:
                            leave.play();
                            while (timer < limit)
                            {
                                float time = clock.getElapsedTime().asSeconds();
                                clock.restart();
                                timer += time;
                            }
                            window.close();
                            // if (!(image.loadFromFile("resources/images/yellow.png")))
                            //         std::cout << "Cannot load image";
                            // if (Keyboard::isKeyPressed(Keyboard::Space)) /* goto menuLabel */ std::cout << "hello" << std::endl;
                            // to be modified
                            break;
                        // case 2:
                        //     window.close();
                        //     break;
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




