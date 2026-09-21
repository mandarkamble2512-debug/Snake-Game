#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "StructsClassesEnums.hpp"

using sf::RenderWindow;

namespace GreenSqures 
{
    DarkGreenSqure SqureDark(Vector2f(0, 0));
    LightGreenSqure SqureLight(Vector2f(0, 0));
}

void DrawScreenGrid (RenderWindow& window)
{
    using GreenSqures::SqureDark;
    using GreenSqures::SqureLight;

    bool IsLightGreenTileDrawn = true;
    for (short X = 0; X <= 640; X = X + 32)
    {
        for (short Y = 0; Y <= 640; Y = Y + 32)
        {
            if (IsLightGreenTileDrawn)
            {
                window.draw(SqureDark.GreenSqure);
                SqureDark.GreenSqure.setPosition(Vector2f(X, Y)); 
                IsLightGreenTileDrawn = false;
            }
            else
            {
                SqureLight.GreenSqure.setPosition(Vector2f(X, Y));
                window.draw(SqureLight.GreenSqure);
                IsLightGreenTileDrawn = true;
            }
        }  
    }
}