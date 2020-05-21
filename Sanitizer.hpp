//This file a sanitizer class file
#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace YL
{
    class  Sanitizer{
    public:
        Sanitizer( GameDataRef data);
        
        void SpawnSanitizer();
        void MoveSpawnSanitizer(float dt);
        void Update(float dt);
        void DrawSanitizer();
        void ReSpawnSanitizer();
        void UpdateCount(int count);
        sf::Sprite & GetSprites () ;
        sf:: Sprite & GetSpawnSprite ();
    private:
        GameDataRef _data;
        
        sf::Sprite _sanitizerSprite;
        sf::Text _sanitizerCountText;
        sf::Sprite _sanitizerSpawnSprite;
        float _rotation;
        void MoveSanitizer (float dt);
    };
}
