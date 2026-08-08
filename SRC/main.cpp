#include <SFML/Graphics.hpp>
#include <vector>
#include "RenderObjects.hpp"
#include "logic.hpp"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using std::vector;

void GameLoop(RenderWindow& window, Event event, short& CurrentDirectionSnakeIsGoing, Snake& snake)
{
    DrawScreenGrid(window);
    MoveSnake(event , snake, CurrentDirectionSnakeIsGoing);
    window.draw(snake.ProtoTypeSnake);
}

int main()
{
    RenderWindow window(VideoMode(640, 640), "Swift Snake");
    Snake snake;
    short CurrentSnakelenth = 1;
    short CurrentDirectionSnakeIsGoing = 0; 
    /*
        0 denotes towards X
        1 denotes towards -Y
        2 denotes towards -X
        3 denotes towards Y
    */

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
        GameLoop(window, event,CurrentDirectionSnakeIsGoing, snake);
        window.display();
    }
    return 0;
}