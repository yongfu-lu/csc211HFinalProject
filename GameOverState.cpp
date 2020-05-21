
#include "GameOverState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"
#include <fstream>

namespace YL
{
    GameOverState::GameOverState(GameDataRef data, int score) : _data( data ), _score( score)
    {
    }
    // Get the hightest score from a file, set everything needed for game over state
    void GameOverState::Init()
    {
        std:: ifstream readFile;
        try{
            readFile.open("Resources/highScore.txt");
            if (readFile.is_open())
            {
                while (!readFile.eof())
                {
                    readFile>> _highScore;
                }
            
            readFile.close();
            }
            else
            {
                throw 1;
            }
        }
        catch (int)
        {
            std::cerr<<"Cannot find score recort"<<std::endl;
        }
        
        std::ofstream writeFile ("Resources/highScore.txt");
        if (writeFile.is_open())
        {
            if( _score > _highScore)
            {
                _highScore = _score;
            }
            writeFile << _highScore;
        }
        writeFile.close();
        
        _data->assets.LoadTexture ("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture ("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        _data->assets.LoadTexture ("Game Over Body", GAME_OVER_BODY_FILEPATH);

        _data->assets.LoadTexture ("Bronze Medal", BRONZE_MEDAL_FILEPATH);
        _data->assets.LoadTexture ("Silver Medal", SILVER_MEDAL_FILEPATH);
        _data->assets.LoadTexture ("Gold Medal", GOLD_MEDAL_FILEPATH);
        _data->assets.LoadTexture ("Platinum Medal", PLATINUM_MEDAL_FILEPATH);

   
        _background.setTexture(_data->assets.GetTexture("Game Over Background"));
        _background2.setTexture(_data->assets.GetTexture("Menu Background" ));
        _background2.setPosition(_background.getGlobalBounds().width  ,0);
        _gameOverTitle.setTexture(this-> _data->assets.GetTexture("Game Over Title"));
        _gameOverContainer.setTexture(this-> _data->assets.GetTexture("Game Over Body"));
        _retryButton.setTexture(this-> _data->assets.GetTexture("Play Button"));
        
        _gameOverContainer.setPosition(_data->window.getSize().x/2 - _gameOverContainer.getGlobalBounds().width/2 , _data->window.getSize().y/2 - _gameOverContainer.getGlobalBounds().height/2);

        _gameOverTitle.setPosition(_data->window.getSize().x/2 - _gameOverTitle.getGlobalBounds().width/2, _gameOverContainer.getPosition().y - _gameOverTitle.getGlobalBounds().height * 1.2);
        
        _retryButton.setPosition(_data->window.getSize().x/2 - _retryButton.getGlobalBounds().width/2, _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height * 1.2);
        
        _scoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _scoreText.setString (std:: to_string (_score));
        _scoreText.setCharacterSize( 56 );
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);
        _scoreText.setPosition(_data->window.getSize().x/10 * 7.25 - 270, _data->window.getSize().y/2.15);
        
        _highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
        _highScoreText.setString (std:: to_string (_highScore));
        _highScoreText.setCharacterSize( 56 );
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width/2, _highScoreText.getGlobalBounds().height/2);
        _highScoreText.setPosition(_data->window.getSize().x/10 * 7.25 - 270, _data->window.getSize().y/1.78);
        
        if (_score >= PLATINUM_MEDAL_SCORE)
        {
            _medal.setTexture(_data->assets.GetTexture("Platinum Medal"));
        }
        else if ( _score >= GOLD_MEDAL_SCORE)
        {
            _medal.setTexture(_data->assets.GetTexture("Gold Medal"));

        }
        else if (_score >= SILVER_MEDAL_SCORE)
        {
            _medal.setTexture(_data->assets.GetTexture("Silver Medal"));
        }
        else
        {
            _medal.setTexture(_data->assets.GetTexture("Bronze Medal"));
        }
        
        _medal.setPosition (750 , 520);
    }
    //switch to game state when user click start
    void GameOverState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data-> window.close();
            }
            
            if (_data->input.IsSpriteClocked(_retryButton, sf::Mouse::Left, _data->window))
            {
                _data->machine.AddState(StateRef (new GameState (_data)),true);
            }
        }
    }

    void GameOverState::Update(float dt)
    {
       
    }

    void GameOverState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw (_background);
        _data->window.draw (_background2);
        _data->window.draw (_gameOverTitle);
        _data->window.draw (_gameOverContainer);
        _data->window.draw (_retryButton);
        _data->window.draw ( _scoreText);
        _data->window.draw (_highScoreText);
        _data->window.draw (_medal);
        _data->window.display();
    }
}


