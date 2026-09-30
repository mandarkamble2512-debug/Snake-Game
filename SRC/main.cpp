#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include "RenderObjects.hpp"
#include "StructsClassesEnums.hpp"
#include "logic.hpp"
#include <cstdlib>
#include <ctime>

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using std::srand;
using std::time;


void GameLoop(RenderWindow& window, Event& event, Snake& snake, GameTime& gameTime)
{
    DrawScreenGrid(window);
    snake.LoadTexturesOfSnake();
    snake.SpawnSnakeFood();
    snake.MoveSnakeHead(event, gameTime);
    snake.HasFoodEaten();
    snake.PlayAnimationForSnakeHead(gameTime);
    snake.DrawSnake(window);
}

int main()
{
    srand(time(NULL));
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
