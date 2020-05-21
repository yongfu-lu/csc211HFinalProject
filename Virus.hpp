/* this virus file will create multiple virus come from right side, user need to control game to avoid it */

#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace YL
{
    class Virus{
    public:
        Virus( GameDataRef data);
        
        void SpawnFirstVirus();
        void SpawnSecondVirus();
        void SpawnThirdVirus();
        void SpawnScoringPipe();
        void MoveVirus (float dt);
        void Draw_Virus();
        void DeleteVirus(int i);
        void DeleteAllVirus();
        
        const std::vector<sf::Sprite> & GetSprites () const;
        std::vector<sf::Sprite> & GetScoringSprites();
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> VirusSprites;
        std::vector<sf::Sprite> scoringPipes;
        
        int _landHeight;
  
    };
}
