/* this file will create game background and make it move*/

#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace YL
{
    class Background{
    public:
        Background( GameDataRef data);
        void MoveBackground (float dt);
        void DrawBackground ();
        
        const std::vector<sf::Sprite> & GetSprites( ) const;
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> _backgroundSprites;
        
    };
}

