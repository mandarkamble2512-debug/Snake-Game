#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "StructsClassesEnums.hpp"

using sf::Vector2f;
using sf::Keyboard;
using sf::Event;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void Sleep()
{
    sleep_for(milliseconds(500));
}

bool IsKeyPressed (Event& event, Keyboard::Key TargetKey)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == TargetKey)
        {
            return true;
        }
    }
    return false;
}

void MoveSnake (Event& event,Snake& snake, short& CurrentDirection)
{
    Vector2f Pos = snake.ProtoTypeSnake.getPosition();

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

    // Boundary Checks (Keep inside 0 to 608 so a 32x32 block stays on screen)
    if (Pos.x >= 640) Pos.x = 608;
    if (Pos.x < 0)    Pos.x = 0;
    if (Pos.y >= 640) Pos.y = 608;
    if (Pos.y < 0)    Pos.y = 0;

    snake.ProtoTypeSnake.setPosition(Pos);
    Sleep();
}

