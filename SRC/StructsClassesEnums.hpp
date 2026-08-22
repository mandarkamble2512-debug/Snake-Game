#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>


using sf::RenderWindow;
using sf::RectangleShape;
using sf::Vector2f;
using sf::Color;
using sf::Texture;
using std::cout;
using std::vector;
using std::string;
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
    vector<Texture> SnakeTextureOfSnakeHeadLeaving;

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
            string FolderPath = "./Assets/Animation/Snake-Head-Leaving-Box"; // ./Assets/Animation/Snake-Head-Leaving-Box
            string FileExtention;
            Texture texture;
            short NumberOfTextureLoaded = 0;

            if (!exists(FolderPath) || !is_directory(FolderPath))
            {
                cout << "Path " << FolderPath << "Does Not Exist" << "\n";
                return;
            }
            
            for (auto File : directory_iterator(FolderPath))
            {
                if (File.is_regular_file())
                {
                    FileExtention = File.path().extension().string();
                }
                
                if (texture.loadFromFile(File.path().string()))
                {
                    SnakeTextureOfSnakeHeadLeaving.push_back(move(texture));
                }
                NumberOfTextureLoaded++;

                if (NumberOfTextureLoaded == 16)
                {
                    HasSnakeHeadLeavingTexturesLoaded = true;
                }
            }
        }
    }

    void ChangeTextureOfSnake ()
    {

    }
};

