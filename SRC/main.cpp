#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Swift Snake");

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
        window.display();
    }

    return 0;
}