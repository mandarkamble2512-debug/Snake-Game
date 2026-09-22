#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "RenderObjects.hpp"
#include "StructsClassesEnums.hpp"
#include "logic.hpp"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;


void GameLoop(RenderWindow& window, Event& event, Snake& snake, GameTime& gameTime)
{
    DrawScreenGrid(window);
    snake.LoadTextures();
    snake.MoveSnakeHead(event, gameTime);
    snake.PlayAnimationForSnakeHead(gameTime);
    snake.DrawSnake(window);
}

int main()
{
    RenderWindow window(VideoMode(640, 640), "Swift Snake");
    Snake snake;
    GameTime gameTime;
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
        GameLoop(window, event, snake, gameTime);
        window.display();
    }
    return 0;
}
