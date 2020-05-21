
#include "Bird.hpp"

namespace YL
{
    //constructor, create character sprite and set position and state
    Bird::Bird(GameDataRef data) : _data ( data)
    {
        _animationIterator = 0;
        _animationFrames.push_back( _data->assets.GetTexture("Bird Frame 1"));
        _animationFrames.push_back( _data->assets.GetTexture("Bird Frame 2"));
        _animationFrames.push_back( _data->assets.GetTexture("Bird Frame 3"));
        _animationFrames.push_back( _data->assets.GetTexture("Bird Frame 4"));
        
        _birdSprite.setTexture( _animationFrames.at(_animationIterator));
        
        _birdSprite.setPosition( _data->window.getSize().x/4 - _birdSprite.getGlobalBounds().width/2, _data->window.getSize().y/2 - _birdSprite.getGlobalBounds().height/2);
        
        _birdState = BIRD_STATE_STILL;
        
        _lifeSprite.setTexture(_data->assets.GetTexture("Bird Frame 1"));
        _lifeSprite.setPosition(600,1020);
        
        _lifeCountText.setFont( _data ->assets.GetFont( "Flappy Font"));
        _lifeCountText.setString("3");
        _lifeCountText.setCharacterSize(64);
        _lifeCountText.setFillColor(sf::Color::White);
        _lifeCountText.setOrigin(_lifeCountText.getGlobalBounds().width/2, _lifeCountText.getGlobalBounds().height/2);
        _lifeCountText.setPosition(740,1070);
        
        deadBodySprite.setTexture(_data->assets.GetTexture("Dead Body"));
        deadBodySprite.setPosition(-500, -500);
    }

    void Bird::Draw()
    {
        _data->window.draw (_birdSprite);
        _data->window.draw (_lifeSprite);
        _data->window.draw (_lifeCountText);
        _data->window.draw (deadBodySprite);
    }

    //make animation of character
    void Bird::Animate(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
        {
            if ( _animationIterator < _animationFrames.size() - 1)
            {
                _animationIterator++;
            }
            else
            {
                _animationIterator = 0;
            }
            _birdSprite.setTexture(_animationFrames.at(_animationIterator));
            _clock.restart();
        }
    }

    //update character, fly and fall
    void Bird::Update( float dt )
    {
        if ( _birdState == BIRD_STATE_FALLING)
        {
            _birdSprite.move(0,GRAVITY * dt );
           
        }
        else if (_birdState == BIRD_STATE_FLYING)
        {
            _birdSprite.move(0, -FLYING_SPEED * dt);
            
        }
        
        if ( _movementClock.getElapsedTime().asSeconds() > FLYING_DURATION )
        {
            _movementClock.restart();
            _birdState = BIRD_STATE_FALLING;
        }
    }

    void Bird::Tap()
    {
        _movementClock.restart();
        _birdState = BIRD_STATE_FLYING;
    }

     sf::Sprite & Bird:: GetSprite () 
    {
        return _birdSprite;
    }

    void Bird::lifeCountUpdate(int count)
    {
        _lifeCountText.setString( std::to_string( count ));
    }

    sf::Sprite & Bird:: GetDeadBody()
    {
        return deadBodySprite;
    }
    
    void Bird::move(float dt)
    {
        deadBodySprite.move(-PIPE_MOVEMENT_SPEED * dt, 0);
    }
}
