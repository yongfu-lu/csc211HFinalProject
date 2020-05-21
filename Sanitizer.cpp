
#include "Sanitizer.hpp"
namespace YL
{
    Sanitizer::Sanitizer( GameDataRef data) : _data(data){
         _sanitizerSprite.setTexture(_data->assets.GetTexture("sanitizer"));
        _sanitizerSprite.setPosition(-100, -100);
        _sanitizerSprite.setOrigin(_sanitizerSprite.getGlobalBounds().width/2, _sanitizerSprite.getGlobalBounds().height/2);
        
        _sanitizerCountText.setFont( _data ->assets.GetFont( "Flappy Font"));
        _sanitizerCountText.setString("1");
        _sanitizerCountText.setCharacterSize(64);
        _sanitizerCountText.setFillColor(sf::Color::White);
        _sanitizerCountText.setOrigin(_sanitizerCountText.getGlobalBounds().width/2, _sanitizerCountText.getGlobalBounds().height/2);
        _sanitizerCountText.setPosition(500,1070);
     }

     void Sanitizer::DrawSanitizer(){
         _data->window.draw( _sanitizerSprite );
         _data->window.draw( _sanitizerCountText);
         _data->window.draw(_sanitizerSpawnSprite);
     }
    
     void Sanitizer::Update( float dt )
        {
            _sanitizerSprite.move( PIPE_MOVEMENT_SPEED * dt * 2,0 );
            _rotation -= 400.0f * dt;
            _sanitizerSprite.setRotation(_rotation);
        }
        
     sf::Sprite & Sanitizer :: GetSprites () 
    {
        return _sanitizerSprite;
    }

    void Sanitizer::UpdateCount(int count)
       {
           _sanitizerCountText.setString( std::to_string( count ));
       }

    void Sanitizer::SpawnSanitizer()
       {
           _sanitizerSpawnSprite.setTexture(_data->assets.GetTexture("sanitizer"));
           _sanitizerSpawnSprite.setPosition(_data->window.getSize().x +1000, rand()%(_data->window.getSize().y -200));
          
       }
    
    void Sanitizer::ReSpawnSanitizer()
    {
        _sanitizerSpawnSprite.setTexture(_data->assets.GetTexture("sanitizer"));
        _sanitizerSpawnSprite.setPosition(_data->window.getSize().x +3500 , rand()%(_data->window.getSize().y -200));
    }

    void Sanitizer::MoveSpawnSanitizer(float dt)
    {
        
        if (_sanitizerSpawnSprite.getPosition().x < -500)
        {
            ReSpawnSanitizer();
            
        }
        else
            _sanitizerSpawnSprite.move(-PIPE_MOVEMENT_SPEED * dt /2.2, 0);
    }
    
    sf::Sprite & Sanitizer:: GetSpawnSprite()
    {
        return _sanitizerSpawnSprite;
    }

}
