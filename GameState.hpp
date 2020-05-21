/* this file handle game state, which is when game is running and user is playing.
 user can control game by clicking mouse */

#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Virus.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"
#include <SFML/Audio.hpp>
#include "Background.hpp"
#include "Mask.hpp"
#include "Inventory.hpp"
#include "Sanitizer.hpp"

namespace YL
{
    class GameState : public State
    {
    public:
        GameState (GameDataRef data);
        
        void Init ();
        void HandleInput();
        void Update (float dt);
        void Draw (float dt);
        
    private:
        GameDataRef _data;
        Background * background;
        Land * land;
        Bird * bird;
        Collision collision;
        Flash *flash;
        HUD * hud;
        Virus * virus;
        sf::Clock clock;
        Mask * mask;
        Sanitizer * sanitizer;
        Inventory * maskInventory;
        
        int sanitizerCount;
        int _gameState;
        int _score;
        int _maskCount;
        int _lifeCount;
        bool attack;
        bool hitVirus;
        sf::Sprite _maskBox;
        sf::Sprite _sanitizerBox;
        
        sf::SoundBuffer _backMusicBuffer;
        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::SoundBuffer _sanitizerBuffer;
        
        sf::Sound _backMusic;
        sf::Sound _hitSound;
        sf::Sound _pointSound;
        sf::Sound _wingSound;
        sf::Sound _sanitizerSound;
        
    };
}
