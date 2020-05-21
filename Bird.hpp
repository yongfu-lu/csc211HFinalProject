/* this file will create the main character that user will control to play this game.*/

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace YL
{
    class Bird{
    public:
        Bird (GameDataRef data);
        
        void Draw ();
        
        void Animate (float dt);
        
        void Update(float dt);
        
        void Tap ();
        
        sf::Sprite & GetSprite () ;
        sf:: Sprite & GetDeadBody();
        
        void lifeCountUpdate (int count);
        void move(float dt);
    private:
        GameDataRef _data;
        
        sf::Sprite _birdSprite;
        sf::Sprite _lifeSprite;
        sf::Text _lifeCountText;
        sf::Sprite deadBodySprite;
        std::vector<sf::Texture> _animationFrames;
        unsigned int _animationIterator;
        
        sf::Clock _clock;
        sf::Clock _movementClock;
        
        int _birdState;
        
        float _rotation;
    };
}
