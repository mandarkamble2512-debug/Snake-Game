#include <SFML/Graphics.hpp>
#include "RenderObjects.hpp"
#include "logic.hpp"

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Color;
using sf::Clock;
using sf::Time;
using sf::seconds;
using sf::milliseconds;

void GameLoop(RenderWindow& window, Event event, Snake& snake, Clock& ClockForMovement, Clock& ClockForAnimation,Time& LastTime, bool& Is250MiliSecondPassed, Time& NextMovementTime, Time& LastTimeForAnimation, Time& NextFrameTime)
{
    DrawScreenGrid(window);
    snake.MoveSnake(event, snake, ClockForMovement, LastTime, Is250MiliSecondPassed, NextMovementTime);
    snake.LoadTextureFromDiskOfSnakeHeadLeavingAnimation();
    snake.ChangeTextureOfSnake(LastTime, ClockForAnimation, NextFrameTime);
    snake.FixSnakeRotation();
    snake.DrawSnake(window);
    // window.draw(snake.ProtoTypeSnake); 
}

int main()
{
    RenderWindow window(VideoMode(640, 640), "Swift Snake");
    Snake snake;
    Clock ClockForMovement;
    Clock ClockForAnimation;
    ClockForMovement.restart();
    ClockForAnimation.restart();
    Time LastTime              = seconds(0.0f);
    Time LastTimeForAnimation  = seconds(0.0f);
    Time NextMovementTime      = milliseconds(250.0f);
    Time NextFrameTime         = milliseconds(15.625); //15.625
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
        GameLoop(window, event, snake, ClockForMovement, ClockForAnimation, LastTime, Is250MiliSecondPassed, NextMovementTime, LastTimeForAnimation, NextFrameTime);
        window.display();
    }
    return 0;
}