
#include "Mask.hpp"
namespace YL
{
    Mask::Mask( GameDataRef data) : _data(data){
        
    }
    
    void Mask::SpawnMask()
    {
        _maskSprite.setTexture(_data->assets.GetTexture("Mask"));
        _maskSprite.setPosition(_data->window.getSize().x + 1000, rand()%(_data->window.getSize().y -200));
        
    }
    //when mask is collected, respawn mask
    void Mask::ReSpawnMask()
    {
        _maskSprite.setTexture(_data->assets.GetTexture("Mask"));
        _maskSprite.setPosition(_data->window.getSize().x + 2000, rand()%(_data->window.getSize().y -200));
        
    }
    //move mask
    void Mask::MoveMask (float dt)
    {
        if (_maskSprite.getPosition().x < -2500)
        {
            SpawnMask();
        }
        else
        {
            float movement = PIPE_MOVEMENT_SPEED * dt / 1.5f;
        
            _maskSprite.move(- movement,0);
        }
    }


    void Mask::DrawMask(){
        _data->window.draw( _maskSprite );
    }
   
    const sf::Sprite & Mask::GetSprites () const{
        return _maskSprite;
    }
       
   
        
  

}
