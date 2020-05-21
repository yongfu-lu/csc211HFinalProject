/* this file handle game over state, when the character die, game switch to this state.*/

#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Background.hpp"


namespace YL
{
    class GameOverState : public State
    {
    public:
        GameOverState (GameDataRef data, int score);
        
        void Init ();
        void HandleInput();
        void Update (float dt);
        void Draw (float dt);
        
    private:
        GameDataRef _data;
     
        sf::Sprite _background;
        sf::Sprite _background2;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _medal;
        
        sf::Text _scoreText;
        sf::Text _highScoreText;
        int _score;
        int _highScore;
    };
}

