#include <SFML/Graphics.hpp>
#include "RenderObjects.hpp"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;

void GameLoop(RenderWindow& window)
{
    DrawScreenGrid(window);
}

int main()
{
    RenderWindow window(VideoMode(640, 640), "Swift Snake");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear(Color::Black);
        GameLoop(window);
        window.display();
    }

    return 0;
}