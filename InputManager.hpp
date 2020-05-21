/* Credit :  Sonarsystems  */
/* this file will handle user input to control and play game. */

#pragma once
#include <SFML/Graphics.hpp>

namespace YL
{
    class InputManager
    {
    public:
        InputManager () {}
        ~InputManager (){}
        
        bool IsSpriteClocked (sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window);
        
        sf::Vector2i GetMousePosition (sf::RenderWindow & window);
    };
}
