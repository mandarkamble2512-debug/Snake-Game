#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <array>


using sf::RenderWindow;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Texture;
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
                // Store directly into the array member
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

    void ChangeTextureOfSnake ()
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

    
};

