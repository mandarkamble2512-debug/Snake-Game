#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using sf::Vector2f;
using sf::Keyboard;
using sf::Event;
using sf::Clock;
using sf::Time;
using sf::milliseconds;
using std::cout;

inline bool IsKeyPressed (Event& event, Keyboard::Key TargetKey) {return (event.type == Event::KeyPressed) && Keyboard::isKeyPressed(TargetKey);} 

