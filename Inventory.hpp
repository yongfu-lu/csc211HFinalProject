/* this file is inventory class, will handle mask that user collected and sanitizer */

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace YL
{
    class Inventory
    {
    public:
        Inventory (GameDataRef data);
        
        void Draw ();
        void UpdateInventory ( int count);
       
        
    private:
        GameDataRef _data;
        
        sf::Text _maskCountText;
       
    };
}
