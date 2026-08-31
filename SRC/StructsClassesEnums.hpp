#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <array>
#include "logic.hpp"


using sf::RenderWindow;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Texture;
using sf::Event;
using sf::Clock;
using sf::Time;
using std::cout;
using std::vector;
using std::string;
using std::array;
using std::move;
using std::filesystem::exists;
using std::filesystem::is_directory;
using std::filesystem::directory_iterator;

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
    bool HasSnakeHeadLeavingTexturesLoaded = false;
    short CurrentTextureIndex = 0;
    short CurrentSnakelenth = 1;
    short CurrentDirectionSnakeIsGoing = 0;
    /*
    0 denotes towards X
    1 denotes towards -Y
    2 denotes towards -X
    3 denotes towards Y
    */
    RectangleShape ProtoTypeSnake;
    vector<Vector2f> CurrentSnakeFormation;
    array<Texture, 16> SnakeTextureOfSnakeHeadLeaving;

    Snake ()
    {
        ProtoTypeSnake.setSize(Vector2f(32,32));
        ProtoTypeSnake.setFillColor(Color(72, 118, 236));
        ProtoTypeSnake.setPosition(Vector2f(0, 0));
    }
    
    void DrawSnake(RenderWindow& window)
    {
        // for (Vector2f& pos : CurrentSnakeFormation)
        // {
        //     ProtoTypeSnake.setPosition(pos);
        //     window.draw(ProtoTypeSnake);
        // }    
        window.draw(ProtoTypeSnake);
    }

    void LoadTextureFromDiskOfSnakeHeadLeavingAnimation ()
    {
        if (!HasSnakeHeadLeavingTexturesLoaded)
        {
            string SpriteLocation[15] = 
            {
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-0.png", 
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-2.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-3.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-4.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-5.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-6.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-7.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-8.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-9.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-10.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-11.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-12.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-13.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-14.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-15.png",
            }; // ./Assets/Animation/Snake-Head-Leaving-Box
            Texture TempTexture;
            short CurrentTextureLodedNumber = 0;

            for (int i = 0; i < 15; i++)
            {
                if (!SnakeTextureOfSnakeHeadLeaving[i].loadFromFile(SpriteLocation[i]))
                {
                    cout << SpriteLocation[i] << " Cannot be loaded properly \n";    
                }
                else
                {
                    cout << SpriteLocation[i] << " Is loaded properly \n";
                }
            }

            HasSnakeHeadLeavingTexturesLoaded = true;
        }   
    }

    void ChangeTextureOfSnake (Time& LastChacked, Clock& clock, Time& NextFrameTime)
    {
        if (Has15_625MiliscondsPassed(LastChacked, clock, NextFrameTime))
        {
            switch (CurrentTextureIndex)
            {
                case 0:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(1));
                    CurrentTextureIndex++;
                    break;
                
                case 1:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(2));
                    CurrentTextureIndex++;
                    break;

                case 2:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(3));
                    CurrentTextureIndex++;
                    break;
                
                case 3:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(4));
                    CurrentTextureIndex++;
                    break;

                case 4:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(4));
                    CurrentTextureIndex++;
                    break;
                
                case 5:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(6));
                    CurrentTextureIndex++;
                    break;

                case 6:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(7));
                    CurrentTextureIndex++;
                    break;

                case 7:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(8));
                    CurrentTextureIndex++;
                    break;

                case 8:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(9));
                    CurrentTextureIndex++;
                    break;

                case 9:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(10));
                    CurrentTextureIndex++;
                    break;
                
                case 10:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(11));
                    CurrentTextureIndex++;
                    break;

                case 11:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(12));
                    CurrentTextureIndex++;
                    break;

                case 12:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(13));
                    CurrentTextureIndex++;
                    break;

                case 13:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(14));
                    CurrentTextureIndex++;
                    break;

                case 14:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(15));
                    CurrentTextureIndex++;
                    break;

                case 15:
                    ProtoTypeSnake.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(0));
                    CurrentTextureIndex = 0;
                    break;
        
                default:
                    break;
            }
        }
    }

    void MoveSnake (Event& event, Snake& snake, Clock& clock, Time& LastTime, bool& Is250MiliSecondPassed, Time NextMovementTime)
    {
        Vector2f PrivousPos = snake.ProtoTypeSnake.getPosition();
        Vector2f Pos = PrivousPos;

        CurrentDirectionSnakeIsGoing = DirectionChanger(event, CurrentDirectionSnakeIsGoing);

        switch (CurrentDirectionSnakeIsGoing)
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
        Is250MiliSecondPassed = Has250MiliscondsPassed(LastTime, clock, NextMovementTime);

        if (!Is250MiliSecondPassed)
        {
            snake.ProtoTypeSnake.setPosition(PrivousPos);
        }
    }

    void FixSnakeRotation ()
    {
        switch (CurrentDirectionSnakeIsGoing)
        {
        case 0:
            ProtoTypeSnake.setRotation(-90);
            break;
        
        case 1:
            ProtoTypeSnake.setRotation(180);
            break;
        
        case 2:
            ProtoTypeSnake.setRotation(-270);
            break;

        case 3:
            ProtoTypeSnake.setRotation(0);
            break;

        default:
            break;
        }
    }
};

