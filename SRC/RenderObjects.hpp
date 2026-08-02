#include <SFML/Graphics.hpp>
#include "StructsClassesEnums.hpp"

using sf::RenderWindow;

void DrawScreenGrid (RenderWindow& window)
{
    bool IsLightGreenTileDrawn = true;
    for (short X = 0; X <= 640; X = X + 32)
    {
        for (short Y = 0; Y <= 640; Y = Y + 32)
        {
            if (IsLightGreenTileDrawn)
            {
                DarkGreenSqure squre(Vector2f(X, Y));
                window.draw(squre.GreenSqure);
                IsLightGreenTileDrawn = false;
            }
            else
            {
                LightGreenSqure squre(Vector2f(X, Y));
                window.draw(squre.GreenSqure);
                IsLightGreenTileDrawn = true;
            }
        }  
    }
}