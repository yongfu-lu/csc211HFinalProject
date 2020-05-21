#include "Virus.hpp"
#include <iostream>
namespace YL
{
    //landHeight will be used for spawning virus
    Virus::Virus (GameDataRef data): _data(data )
        {
            _landHeight = _data->assets.GetTexture("Land").getSize().y;
     
        }

    void Virus::Draw_Virus()
    {
        for (unsigned short int i=0; i<VirusSprites.size(); i++)
        {
            _data->window.draw(VirusSprites.at(i));
        }
    }
    
    void Virus::SpawnFirstVirus()
    {
        sf::Sprite sprite( _data->assets.GetTexture("Virus"));
        sf::Vector2i position (_data->window.getSize().x,rand()%(_data->window.getSize().y- _landHeight - 50));
        sprite.setPosition(position.x,position.y);
        VirusSprites.push_back(sprite);
    }

    void Virus::SpawnSecondVirus()
    {
        sf::Sprite sprite( _data->assets.GetTexture("Small Virus"));
        sf::Vector2i position (_data->window.getSize().x,rand()%(_data->window.getSize().y- _landHeight - 50));
        sprite.setPosition(position.x,position.y);
        VirusSprites.push_back(sprite);
    }

    void Virus::SpawnThirdVirus()
    {
        sf::Sprite sprite( _data->assets.GetTexture("Small Virus"));
        sf::Vector2i position (_data->window.getSize().x,rand()%(_data->window.getSize().y - _landHeight- 50));
        sprite.setPosition(position.x,position.y);
        VirusSprites.push_back(sprite);
    }
    //invisible sprite for counting score
    void Virus::SpawnScoringPipe()
    {
        sf::Sprite sprite( _data->assets.GetTexture("Scoring Pipe"));
        sprite.setPosition(_data->window.getSize().x, 0);
        
        scoringPipes.push_back(sprite);
    }
    //move virus
    void Virus::MoveVirus(float dt)
    {
        for (unsigned short int i = 0; i< VirusSprites.size(); i++)
        {
            if (VirusSprites.at(i).getPosition().x < -100)
            {
                VirusSprites.erase(VirusSprites.begin()+i);
            }
            else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
            
                VirusSprites.at(i).move(-movement,0);
            }
        }
        
        for (unsigned short int i = 0; i< scoringPipes.size(); i++)
        {
            if (scoringPipes.at(i).getPosition().x < -100)
            {
                scoringPipes.erase(scoringPipes.begin()+i);
            }
            else
            {
                float movement = PIPE_MOVEMENT_SPEED * dt;
            
                scoringPipes.at(i).move(-movement,0);
            }
        }
        
    }

    const std::vector<sf::Sprite> & Virus:: GetSprites () const
    {
        return VirusSprites;
    }
    
    std::vector<sf::Sprite> & Virus:: GetScoringSprites ()
       {
           return scoringPipes;
       }

    void Virus::DeleteVirus( int i){
        VirusSprites[i].setPosition(-200, -200);
    }

    void Virus::DeleteAllVirus()
    {
        VirusSprites.clear();
        scoringPipes.clear();
    }
}
