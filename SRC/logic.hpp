#include <SFML/Graphics.hpp>
#include <iostream>
#include "StructsClassesEnums.hpp"

using sf::Vector2f;
using std::cout;

void MoveSnake (Snake& snake, short& CurrentDirection)
{
    Vector2f Pos = snake.ProtoTypeSnake.getPosition();
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

    cout << "Moved The snake" << "\n";

    // Boundary Checks (Keep inside 0 to 608 so a 32x32 block stays on screen)
    if (Pos.x >= 640) Pos.x = 608;
    if (Pos.x < 0)    Pos.x = 0;
    if (Pos.y >= 640) Pos.y = 608;
    if (Pos.y < 0)    Pos.y = 0;

    snake.ProtoTypeSnake.setPosition(Pos);
}
