#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StructsClassesEnums.hpp"

using sf::Vector2f;
using sf::Keyboard;
using sf::Event;
using sf::Clock;
using sf::Time;
using sf::seconds;
using sf::milliseconds;
using std::cout;

bool Has250MiliscondsPassed(Time& LastChecked, Clock& clock, Time& NextMovementTime) 
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

bool Has15_625MiliscondsPassed (Time& LastChecked, Clock& clock, Time& NextMovementTime) 
{
    Time TimeNow = clock.getElapsedTime();
    if (NextMovementTime.asMilliseconds() <= TimeNow.asMilliseconds())
    {
        LastChecked = NextMovementTime;
        // NextMovementTime += milliseconds(15.625);
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

short DirectionChanger (Event& event, short CurrentDirection)
{
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
    return CurrentDirection;
}

 