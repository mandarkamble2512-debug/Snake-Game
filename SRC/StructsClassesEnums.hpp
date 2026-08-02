#include <SFML/Graphics.hpp>

using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;

struct LightGreenSqure
{
    RectangleShape GreenSqure;

    LightGreenSqure ()
    {
        GreenSqure.setSize(Vector2f(32,32));
        GreenSqure.setFillColor(Color(170, 215, 81));
    }
};

struct DarkGreenSqure
{
    RectangleShape GreenSqure;

    DarkGreenSqure ()
    {
        GreenSqure.setSize(Vector2f(32, 32));
        GreenSqure.setFillColor(Color(162, 209, 73));
    }
};

