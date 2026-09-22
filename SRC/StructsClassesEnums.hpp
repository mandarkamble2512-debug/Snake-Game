#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
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
using sf::microseconds;
using sf::seconds;
using std::cout;
using std::vector;
using std::string;
using std::array;
using std::move;
using std::filesystem::exists;
using std::filesystem::is_directory;
using std::filesystem::directory_iterator;

enum class AnimationState
{
    SnakeHeadLeaving,
    SnakeHeadEntering
};

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

struct GameTime 
{
    Clock ClockForMovement;
    Clock ClockForAnimationOfSnakeHeadLeaving;
    Clock ClockForAnimtaionOfSnakeHeadEntering;

    Time FixedTimeForNextFrameInSnakeHeadEntering = microseconds(7812); // 7812.5
    Time FixedTimeForNextFrameInSnakeHeadLeaving = microseconds(15625); // 15625
    Time FixedTimeForNextMovement = microseconds(250000);

    Time& NextMovementTime = FixedTimeForNextMovement;
    Time& NextAnimationTimeForSnakeHeadLeaving = FixedTimeForNextFrameInSnakeHeadLeaving;
    Time& NextAnimationTimeForSnakeHeadEntering = FixedTimeForNextFrameInSnakeHeadEntering;

    Time TimeNow;
    Time OldTimeNow;
    
    GameTime ()
    {
        ClockForAnimationOfSnakeHeadLeaving.restart();
        ClockForMovement.restart();
    }

    bool HasXMiliscondsPassed (Clock& clock, Time& NextTriggerTime, Time& Interval)
    {
        TimeNow = clock.getElapsedTime();
        if (NextTriggerTime.asMicroseconds() <= TimeNow.asMicroseconds())
        {
            // NextTriggerTime += microseconds(Interval.asMicroseconds());
            if (TimeNow != microseconds(0)) 
            {
                OldTimeNow = TimeNow;
            }
            clock.restart();
            return true;
        }
        return false;
    }
};


struct Snake
{
    bool HasSnakeHeadLeavingTexturesLoaded = false;
    bool HasSnakeHeadEnteringTextureLoaded  = false;
    bool HasSnakeFoodTextureLoaded = false;
    short CurrentTextureIndexOfSnakeHeadLeavingBoxAnimation = 0;
    short CurrentTextureIndexOfSnakeHeadEnteringBoxAnimation = 0;
    short CurrentSnakelenth = 1;
    short CurrentDirectionSnakeIsGoing = 0;
    /*
    0 denotes towards X
    1 denotes towards -Y
    2 denotes towards -X
    3 denotes towards Y
    */
    AnimationState StateOfAnimation = AnimationState::SnakeHeadEntering;
    RectangleShape SnakeHead;
    RectangleShape SnakeTail;
    RectangleShape SnakeFood;
    Texture SnakeFoodTexture;
    array<RectangleShape, 396> SnakeBody;
    array<Texture, 16> SnakeTextureOfSnakeHeadLeaving;
    array<Texture, 34> SnakeTextureOfSnakeHeadEntering;

    Snake ()
    {
        SnakeHead.setSize(Vector2f(32,32));
        SnakeHead.setFillColor(Color(72, 118, 236));
        SnakeHead.setPosition(Vector2f(16, 16));
        SnakeHead.setOrigin(Vector2f(16, 16));

        SnakeTail.setSize(Vector2f(32, 32));
        SnakeTail.setFillColor(Color(72, 118, 236));
        SnakeTail.setOrigin(16, 16);
        SnakeTail.setPosition(Vector2f(0, 0));
    }
    
    void DrawSnake(RenderWindow& window)
    {
        // for (Vector2f& pos : CurrentSnakeFormation)
        // {
        //     ProtoTypeSnake.setPosition(pos);
        //     window.draw(ProtoTypeSnake);
        // }    
        window.draw(SnakeHead);
        window.draw(SnakeTail);
    }

    void LoadTextureFromDiskOfSnakeFood ()
    {
        if (!HasSnakeFoodTextureLoaded) 
        {
            if (!HasSnakeFoodTextureLoaded)
            {
                if (!SnakeFoodTexture.loadFromFile("./Assets/Animation/Heart/pixil-frame-0.png"))
                {
                    cout << "Snake Food Texture Could Not Be Loaded\n";
                }
                else 
                {
                    cout << "Snake Food Texture Loaded\n";
                    SnakeFood.setTexture(&SnakeFoodTexture);
                    HasSnakeFoodTextureLoaded = true;
                }
            }
        }
    }

    void LoadTextureFromDiskOfSnakeHeadEnteringaAnimation ()
    {
        if (!HasSnakeHeadEnteringTextureLoaded)
        {
            string SpriteLocation[32] = 
            {
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-0.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-1.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-3.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-4.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-5.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-6.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-7.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-8.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-9.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-10.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-11.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-12.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-13.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-14.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-15.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-16.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-17.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-18.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-19.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-20.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-21.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-22.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-23.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-24.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-25.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-26.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-27.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-28.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-29.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-30.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-31.png",
                "./Assets/Animation/Snake-Head-Entering-Box/pixil-frame-32.png",
            }; // ./Assets/Animation/Snake-Head-Entering-Box

            for (short i = 0; i < 32; i++) 
            {
                if (!SnakeTextureOfSnakeHeadEntering[i].loadFromFile(SpriteLocation[i])) 
                {
                    cout << SpriteLocation[i] << " Cannot be loaded properly \n";
                    return;
                }
                else 
                {
                    cout << SpriteLocation[i] << " Is loaded properly \n";
                }
            }
            HasSnakeHeadEnteringTextureLoaded = true;
        }
        return;
    }

    void LoadTextureFromDiskOfSnakeHeadLeavingAnimation ()
    {
        if (!HasSnakeHeadLeavingTexturesLoaded)
        {
            string SpriteLocation[16] = 
            {
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-0.png",
                "./Assets/Animation/Snake-Head-Leaving-Box/pixil-frame-1.png",
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

            for (int i = 0; i < 16; i++)
            {
                if (!SnakeTextureOfSnakeHeadLeaving[i].loadFromFile(SpriteLocation[i]))
                {
                    cout << SpriteLocation[i] << " Cannot be loaded properly \n";    
                    return;
                }
                else
                {
                    cout << SpriteLocation[i] << " Is loaded properly \n";
                }
            }

            HasSnakeHeadLeavingTexturesLoaded = true;
        }
        return;
    }

    void LoadTextures ()
    {
        LoadTextureFromDiskOfSnakeHeadEnteringaAnimation();
        LoadTextureFromDiskOfSnakeHeadLeavingAnimation();
        LoadTextureFromDiskOfSnakeFood();
    }

    void ChangeTextureOfSnakeFromSnakeHeadEnteringBoxSprites (GameTime& gameTime)
    {
        if (gameTime.HasXMiliscondsPassed(gameTime.ClockForAnimtaionOfSnakeHeadEntering, gameTime.NextAnimationTimeForSnakeHeadEntering, gameTime.FixedTimeForNextFrameInSnakeHeadEntering)) 
        {
            if (CurrentTextureIndexOfSnakeHeadEnteringBoxAnimation >= 32) 
            {
                CurrentTextureIndexOfSnakeHeadEnteringBoxAnimation = 0;
                StateOfAnimation = AnimationState::SnakeHeadLeaving;
            }
            else 
            {
                SnakeHead.setTexture(&SnakeTextureOfSnakeHeadEntering.at(CurrentTextureIndexOfSnakeHeadEnteringBoxAnimation));
                CurrentTextureIndexOfSnakeHeadEnteringBoxAnimation++;
            }
        }
    }

    void ChangeTextureOfSnakeFromSnakeHeadLeavingBoxSprites (GameTime& gameTime)
    {
        if (gameTime.HasXMiliscondsPassed(gameTime.ClockForAnimationOfSnakeHeadLeaving, gameTime.NextAnimationTimeForSnakeHeadLeaving, gameTime.FixedTimeForNextFrameInSnakeHeadLeaving)) 
        {
            if (CurrentTextureIndexOfSnakeHeadLeavingBoxAnimation >= 16) 
            {
                CurrentTextureIndexOfSnakeHeadLeavingBoxAnimation = 0;
                StateOfAnimation = AnimationState::SnakeHeadEntering;
            }
            else 
            {
                SnakeHead.setTexture(&SnakeTextureOfSnakeHeadLeaving.at(CurrentTextureIndexOfSnakeHeadLeavingBoxAnimation));
                CurrentTextureIndexOfSnakeHeadLeavingBoxAnimation++;
            }
        }
    }

    void PlayAnimationForSnakeHead (GameTime& gameTime)
    {
        if (StateOfAnimation == AnimationState::SnakeHeadEntering) 
        {
            ChangeTextureOfSnakeFromSnakeHeadEnteringBoxSprites(gameTime);
        }
        else if (StateOfAnimation == AnimationState::SnakeHeadLeaving) 
        {
            ChangeTextureOfSnakeFromSnakeHeadLeavingBoxSprites(gameTime);
        }
    }

    void FixSnakeRotation ()
    {
        switch (CurrentDirectionSnakeIsGoing)
        {
        case 0:
            SnakeHead.setRotation(-90);
            break;
        
        case 1:
            SnakeHead.setRotation(180);
            break;
        
        case 2:
            SnakeHead.setRotation(-270);
            break;

        case 3:
            SnakeHead.setRotation(0);
            break;

        default:
            break;
        }
    }

    short DirectionChanger (Event& event, short& CurrentDirection, GameTime& gameTime)
    {
        if (IsKeyPressed(event ,Keyboard::W) || IsKeyPressed(event, Keyboard::Up))
        {
            if (CurrentDirection != 3) 
            {
                CurrentDirection = 1;
            }
        }
        else if (IsKeyPressed(event, Keyboard::A) || IsKeyPressed(event, Keyboard::Left))
        {
            if (CurrentDirection != 0) 
            {
                CurrentDirection = 2;
            }
        }
        else if (IsKeyPressed(event, Keyboard::S) || IsKeyPressed(event, Keyboard::Down))
        {
            if (CurrentDirection != 1) 
            {
                CurrentDirection = 3;
            }
        }
        else if (IsKeyPressed(event, Keyboard::D) || IsKeyPressed(event, Keyboard::Right))
        {
            if (CurrentDirection != 2) 
            {
                CurrentDirection = 0;
            }
        }
        return CurrentDirection;
    }

    void MoveSnakeHead (Event& event, GameTime& gameTime)
    {
        CurrentDirectionSnakeIsGoing = DirectionChanger(event, CurrentDirectionSnakeIsGoing, gameTime);
        if (gameTime.HasXMiliscondsPassed(gameTime.ClockForMovement, gameTime.NextMovementTime, gameTime.FixedTimeForNextMovement)) 
        {
            Vector2f PrivousPos = SnakeHead.getPosition();
            Vector2f Pos = PrivousPos;

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

            if (Pos.x >= 640) Pos.x = 608 + 16;
            if (Pos.x < 0)    Pos.x = 16;
            if (Pos.y >= 640) Pos.y = 608 + 16;
            if (Pos.y < 0)    Pos.y = 16;

            SnakeHead.setPosition(Pos);
            SnakeTail.setPosition(PrivousPos);
            FixSnakeRotation();
        }

    }
};

