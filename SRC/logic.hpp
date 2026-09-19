#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using sf::Vector2f;
using sf::Keyboard;
using sf::Event;
using sf::Clock;
using sf::Time;
using sf::milliseconds;
using std::cout;

namespace Input 
{
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
}
