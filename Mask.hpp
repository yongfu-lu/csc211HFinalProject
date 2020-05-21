/* this mask file will handle mask randomly come from the right side, user can collect it */
#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace YL
{
    class  Mask{
    public:
        Mask( GameDataRef data);
        
        void SpawnMask();
        void MoveMask (float dt);
        void DrawMask();
        void ReSpawnMask();
        
        const sf::Sprite & GetSprites () const;
    private:
        GameDataRef _data;
        
        sf::Sprite _maskSprite;
        
  
    };
}
