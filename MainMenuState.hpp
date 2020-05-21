/* This file is for Main menu state, where user can click to start game */

#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Background.hpp"

namespace YL
{
    class MainMenuState : public State
    {
    public:
        MainMenuState (GameDataRef data);
        
        void Init ();
        void HandleInput();
        void Update (float dt);
        void Draw (float dt);
        
    private:
        GameDataRef _data;
        
        sf::Sprite _background;
        sf::Sprite _background2;
        sf::Sprite _title;
        sf::Sprite _playButton;
        sf::Sprite _aboutButton;
        sf::Sprite _aboutWindow;
    };
}

