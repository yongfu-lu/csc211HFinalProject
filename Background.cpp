#include "Background.hpp"
#include "DEFINITIONS.hpp"

namespace YL
{
    //vector of background, set position
    Background::Background (GameDataRef data) :  _data(data)
    {
        sf::Sprite sprite (_data->assets.GetTexture("Game Background"));
        sf::Sprite sprite2 (_data->assets.GetTexture("Game Background"));
        sf::Sprite sprite3 (_data->assets.GetTexture("Game Background"));

        sprite.setPosition(0, 0);
        sprite2.setPosition(sprite.getGlobalBounds().width  ,0);
        sprite3.setPosition(sprite.getGlobalBounds().width * 2 ,0);
        
        _backgroundSprites.push_back(sprite);
        _backgroundSprites.push_back(sprite2);
        _backgroundSprites.push_back(sprite3);
    }
    
    //move background sprite
    void Background::MoveBackground(float dt)
    {
        for (unsigned short int i=0 ; i< _backgroundSprites.size(); i++)
        {
            float movement = PIPE_MOVEMENT_SPEED * dt /4  ;
            _backgroundSprites.at(i).move(-movement, 0.0f);
            
            if (_backgroundSprites.at(i).getPosition().x <  0 - _backgroundSprites.at(i).getGlobalBounds().width)
            {
                sf::Vector2f position( _backgroundSprites.at(i).getGlobalBounds().width * 2, _backgroundSprites.at(i).getPosition().y);
                _backgroundSprites.at(i).setPosition(position);
            }
        }
    }

    void Background::DrawBackground()
    {
        for (unsigned short int i = 0; i<_backgroundSprites.size(); i++)
        {
            _data->window.draw(_backgroundSprites.at(i));
        }
    }

    const std::vector<sf::Sprite> & Background:: GetSprites( ) const
    {
        return _backgroundSprites;
    }

}

