/* this file check if character hit ground, virus or mask */

#pragma once
#include <SFML/Graphics.hpp>

namespace YL
{
    class Collision
    {
    public:
        Collision( );
        bool CheckSpriteCollision (sf::Sprite sprite1, sf::Sprite sprite2);
        bool CheckSpriteCollision (sf::Sprite sprite1,float scale1, sf::Sprite sprite2, float scale2);
    };
}
