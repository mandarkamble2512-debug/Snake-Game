#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using sf::RenderWindow;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using std::vector;

struct LightGreenSqure
{
    RectangleShape GreenSqure;

    LightGreenSqure (Vector2f Pos)
    {
        GreenSqure.setSize(Vector2f(32,32));
        GreenSqure.setFillColor(Color(170, 215, 81));
        GreenSqure.setPosition(Pos);
    }
};

struct DarkGreenSqure
{
    RectangleShape GreenSqure;

    DarkGreenSqure (Vector2f Pos)
    {
        GreenSqure.setSize(Vector2f(32, 32));
        GreenSqure.setFillColor(Color(162, 209, 73));
        GreenSqure.setPosition(Pos);
    }
};

struct Snake
{
    RectangleShape ProtoTypeSnake;
    vector<Vector2f> CurrentSnakeFormation;

    Snake ()
    {
        ProtoTypeSnake.setSize(Vector2f(32,32));
        ProtoTypeSnake.setFillColor(Color(72, 118, 236));
        ProtoTypeSnake.setPosition(Vector2f(0, 0));
    }
    
    void DrawSnake(RenderWindow& window)
    {
        for (Vector2f& pos : CurrentSnakeFormation)
        {
            ProtoTypeSnake.setPosition(pos);
            window.draw(ProtoTypeSnake);
        }    
    }

    void AddToSnakeLenth (short Lenth)
    {
        
    }

    void ChangeSprite (short IndexNumberOfSprite)
    {
        
    }
};

