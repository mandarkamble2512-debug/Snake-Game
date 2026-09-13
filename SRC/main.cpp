#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "RenderObjects.hpp"
#include "StructsClassesEnums.hpp"
#include "logic.hpp"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;


void GameLoop(RenderWindow& window, Event event, Snake& snake, bool Is250MiliSecondPassed, GameTime& gameTime)
{
    DrawScreenGrid(window);
    snake.LoadTextures();
    snake.MoveSnake(event, snake, gameTime);
    snake.ChangeTextureOfSnakeFromSnakeHeadLeavingBoxSprites(gameTime);
    snake.DrawSnake(window);
    // window.draw(snake.ProtoTypeSnake); 
}

int main()
{
    RenderWindow window(VideoMode(640, 640), "Swift Snake");
    Snake snake;
    GameTime gameTime;
    bool Is250MiliSecondPassed = 0;

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
        GameLoop(window, event, snake, Is250MiliSecondPassed, gameTime);
        window.display();
    }
    return 0;
}