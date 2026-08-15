#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "StructsClassesEnums.hpp"

using sf::Vector2f;
using sf::Keyboard;
using sf::Event;
using sf::Clock;
using sf::Time;
using sf::seconds;
using sf::milliseconds;
using std::cout;

bool HasOneSecondPassed(Time& LastChecked, Clock& clock, Time& NextMovementTime) 
{
    Time TimeNow = clock.getElapsedTime();    
    if (NextMovementTime.asMilliseconds() <= TimeNow.asMilliseconds())
    {
        LastChecked = NextMovementTime;
        // NextMovementTime = clock.getElapsedTime() + seconds(1);
        clock.restart();
        return true;
    }
    return false;
}

bool IsKeyPressed (Event& event, Keyboard::Key TargetKey)
{
    if (event.type == Event::KeyPressed)
    {
        if (Keyboard::isKeyPressed(TargetKey))
        {
            return true;
        }
    }
    return false;
}

void MoveSnake (Event& event,Snake& snake, short& CurrentDirection, Clock& clock, Time& LastTime, bool& IsOneSecondPassed, Time NextMovementTime)
{
    Vector2f PrivousPos = snake.ProtoTypeSnake.getPosition();
    Vector2f Pos = PrivousPos;

    if (IsKeyPressed(event ,Keyboard::W) || IsKeyPressed(event, Keyboard::Up))
    {
        CurrentDirection = 1;
    }
    if (IsKeyPressed(event, Keyboard::A) || IsKeyPressed(event, Keyboard::Left))
    {
        CurrentDirection = 2;
    }
    if (IsKeyPressed(event, Keyboard::S) || IsKeyPressed(event, Keyboard::Down))
    {
        CurrentDirection = 3;
    }
    if (IsKeyPressed(event, Keyboard::D) || IsKeyPressed(event, Keyboard::Right))
    {
        CurrentDirection = 0;
    }

    switch (CurrentDirection)
    {
    case 0:
        Pos.x += 32;
        break;
    
    case 1:
        Pos.y -= 32;
        break;

    case 2:
        Pos.x -= 32;
        break;

    case 3:
        Pos.y += 32;
        break;
    }

    if (Pos.x >= 640) Pos.x = 608;
    if (Pos.x < 0)    Pos.x = 0;
    if (Pos.y >= 640) Pos.y = 608;
    if (Pos.y < 0)    Pos.y = 0;
    snake.ProtoTypeSnake.setPosition(Pos);
    IsOneSecondPassed = HasOneSecondPassed(LastTime, clock, NextMovementTime);
    if (!IsOneSecondPassed)
    {
        snake.ProtoTypeSnake.setPosition(PrivousPos);
    }
    
}