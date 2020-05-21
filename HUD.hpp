/* this file will keep tracking the score user got */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace YL
{
    class HUD
    {
    public:
        HUD (GameDataRef data);
        
        void Draw ();
        void UpdateScore ( int score);
    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}
