
#include "GameState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameOverState.hpp"

namespace YL
{
    GameState::GameState(GameDataRef data) : _data( data )
    {
    }
    //load sound effect, set virus, land, backgroud  ect.
    void GameState::Init()
    {
        try{
            if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH ))
            {
                throw 1;
            }
            if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH ))
            {
                throw 1;
            }
            if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH ))
            {
                throw 1;
            }
            if (!_backMusicBuffer.loadFromFile(BACK_MUSIC_FILEPATH ))
            {
                throw 1;
            }
            if (!_sanitizerBuffer.loadFromFile(SANITIZER_MUSIC))
            {
                throw 1;
            }
        }
        catch (int)
        {
            std::cerr<<"Cannot find audio files"<<std::endl;
        }
        
        
        _hitSound.setBuffer ( _hitSoundBuffer);
        _wingSound.setBuffer ( _wingSoundBuffer);
        _pointSound.setBuffer ( _pointSoundBuffer);
        _backMusic.setBuffer(_backMusicBuffer);
        _sanitizerSound.setBuffer(_sanitizerBuffer);
        _backMusic.setLoop(true);
        _backMusic.play();
        

        //load texture and font
        _data->assets.LoadTexture ("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture ("Virus", VIRUS_FILEPATH);
        _data->assets.LoadTexture ("Small Virus", SMALL_VIRUS_FILEPATH);
        _data->assets.LoadTexture ("Mask", MASK_FILEPATH);
        _data->assets.LoadTexture ("Big Mask", BIG_MASK_FILEPATH);
        _data->assets.LoadTexture ("Land", LAND_FILEPATH);
        _data->assets.LoadTexture ("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture ("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture ("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture ("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        _data->assets.LoadTexture ("Dead Body", DEAD_BODY_FILEPATH);
        _data->assets.LoadTexture ("Scoring Pipe", SCORING_PIPE_FILEPATH);
        _data->assets.LoadTexture("sanitizer", SANITIZER_FILEPATH);
        _data->assets.LoadFont ("Flappy Font", FLAPPY_FONT_FILEPATH);
        

        background = new Background (_data );
        virus = new Virus (_data);
        land = new Land (_data);
        bird = new Bird (_data);
        flash = new Flash( _data);
        hud = new HUD(_data);
        mask = new Mask(_data);
        maskInventory = new Inventory(_data);
        sanitizer = new Sanitizer( _data ); 
        
        sanitizerCount = 1;
        _score = 0;
        _maskCount = 1;
        _lifeCount = 2;
        
        
        hud->UpdateScore(_score);
        maskInventory->UpdateInventory(_maskCount);
        bird->lifeCountUpdate(_lifeCount);
        sanitizer->UpdateCount(sanitizerCount);
        
        _maskBox.setTexture(_data->assets.GetTexture("Big Mask"));
        _maskBox.setPosition(0, 950);
        _sanitizerBox.setTexture(_data->assets.GetTexture("sanitizer"));
        _sanitizerBox.setPosition(400,1000);
        
        _gameState = GameStates::eReady;
        mask->SpawnMask();
        sanitizer->SpawnSanitizer();
        
        attack = false;
        hitVirus = false;
    }
    //handle user input when click mouse
    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data-> window.close();
            }
            //control up and down
            if (_data->input.IsSpriteClocked(background->GetSprites()[0], sf::Mouse::Left,_data->window)|| _data->input.IsSpriteClocked(background->GetSprites()[1],sf::Mouse::Left,_data->window)||  _data->input.IsSpriteClocked(background->GetSprites()[2], sf::Mouse::Left, _data->window))
            {
                if (_gameState!= GameStates::eGameOver)
                {
                    _gameState = GameStates::ePlaying;
                    bird->Tap();
                    
                    _wingSound.play();
                }
            }
            //click right button, use sanitizer, will kill virus in Update function in later code
            
            if (_data->input.IsSpriteClocked(background->GetSprites()[0], sf::Mouse::Right,_data->window)|| _data->input.IsSpriteClocked(background->GetSprites()[1],sf::Mouse::Right,_data->window)||  _data->input.IsSpriteClocked(background->GetSprites()[2], sf::Mouse::Right, _data->window))
            {
                if (_gameState == GameStates::ePlaying)
                {
                    if (sanitizerCount>0 && (!attack))
                    {
                        sanitizerCount--;
                        sanitizer->GetSprites().setPosition(bird->GetSprite().getPosition().x, bird->GetSprite().getPosition().y);
                        attack = true;
                        _sanitizerSound.play();
                        sanitizer->UpdateCount(sanitizerCount);
                    }
                }
            }
        }
    }
    //move sprite, check if character die or get score or get mask
    void GameState::Update(float dt)
    {
        
        if (_gameState!= GameStates::eGameOver)
        {
            bird->Animate( dt);
            land->MoveLand(dt);
            background->MoveBackground(dt);
           
        }
        
        if (_gameState == GameStates::ePlaying)
        {
    
            virus->MoveVirus(dt);
            mask->MoveMask( dt);
            sanitizer->MoveSpawnSanitizer(dt);
            if(clock.getElapsedTime().asSeconds()> PIPE_SPAWN_FREQUENCY )
            {
           
                virus->SpawnFirstVirus();
                virus->SpawnSecondVirus();
                virus->SpawnThirdVirus();
                if (_score >10 )
                {
                    virus->SpawnThirdVirus();
                    if (_score > 20)
                    {
                        virus->SpawnThirdVirus();
                        if (_score > 30)
                        {
                            virus->SpawnFirstVirus();
                            if(_score >50)
                            {
                                virus->SpawnSecondVirus();
                            }
                        }
                    }
                }
                
                virus->SpawnScoringPipe();
                mask->MoveMask( dt);
                clock.restart();
            }
     
            bird->Update( dt);
            
            //collecting mask and sanitizer
            if (collision.CheckSpriteCollision(bird->GetSprite(),0.9f, mask->GetSprites(),1.0f))
            {
                mask->ReSpawnMask();
                _maskCount++;
                _pointSound.play();
                maskInventory->UpdateInventory(_maskCount);
            }
            
            if (collision.CheckSpriteCollision(bird->GetSprite(),0.9f, sanitizer->GetSpawnSprite(),1.0f))
                      {
                          sanitizer->SpawnSanitizer();
                          sanitizerCount++;
                          sanitizer->UpdateCount(sanitizerCount);
                          _pointSound.play();
                      }
            
            //hit ground, die
            std::vector<sf::Sprite> landSprite = land ->GetSprites();
            for (int i = 0; i<landSprite.size() ; i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(),0.9f, landSprite.at(i),1.0f))
                {
                    hitVirus = false;
                    _lifeCount--;
                    _hitSound.play();
                    if (_lifeCount < 0)
                    {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _backMusic.stop();
                    }
                    else
                    {
                        bird->lifeCountUpdate(_lifeCount);
                        bird->GetDeadBody().setPosition(bird->GetSprite().getPosition().x, bird->GetSprite().getPosition().y);
                        bird->GetSprite().setPosition(400,500);
                        
                    }
                }
            }
            
            //hit celling, die
            if (bird->GetSprite().getPosition().y < -200 )
            {
                hitVirus = false;
                _lifeCount--;
                _hitSound.play();
                if (_lifeCount < 0)
                {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _backMusic.stop();
                }
                else
                {
                    bird->lifeCountUpdate(_lifeCount);
                    bird->GetDeadBody().setPosition(bird->GetSprite().getPosition().x, bird->GetSprite().getPosition().y);
                    bird->GetSprite().setPosition(400,500);
                }
            }
            
            //hit virus, use mask to protect or die
            std::vector<sf::Sprite> virusSprite = virus ->GetSprites();
            for (int i = 0; i<virusSprite.size() ; i++)
            {
                if (collision.CheckSpriteCollision(bird->GetSprite(),0.8,virusSprite.at(i), 0.667))
                {
                    if (_maskCount< 1)
                    {
                        hitVirus = true;
                       _lifeCount--;
                        _hitSound.play();
                        if (_lifeCount < 0)
                        {
                            _gameState = GameStates::eGameOver;
                            clock.restart();
                            _backMusic.stop();
                        }
                        else
                        {
                            bird->lifeCountUpdate(_lifeCount);
                            bird->GetDeadBody().setPosition(bird->GetSprite().getPosition().x, bird->GetSprite().getPosition().y);
                            bird->GetSprite().setPosition(400,500);
                            virus->DeleteAllVirus();
                            
                        }
                    }
                    else
                    {
                        _maskCount--;
                        maskInventory->UpdateInventory(_maskCount);
                        virus->DeleteVirus(i);
                        _hitSound.play();
                    }
                }
            }
            //get score when pass virus
            if (_gameState == GameStates::ePlaying)
            {
                std::vector<sf::Sprite> &scoringSprite = virus ->GetScoringSprites();
                for (int i = 0; i<scoringSprite.size() ; i++)
                {
                    if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f,scoringSprite.at(i), 0.4f))
                    {
                        _score++;
                        _pointSound.play();
                        hud->UpdateScore(_score);
                        scoringSprite.erase (scoringSprite.begin() +i );
                    }
                }
            }
            // use sanitizer kill virus
            if (attack)
            {
                sanitizer->Update(dt);
                if (sanitizer->GetSprites().getPosition().x >2000)
                {
                    attack = false;
                }
                for (int i = 0; i<virusSprite.size() ; i++)
                {
                    if (collision.CheckSpriteCollision(sanitizer->GetSprites(),0.8,virusSprite.at(i), 0.667))
                    {
                        virus->DeleteVirus(i);
                        _hitSound.play();
                    }
                }
                          
            }
        }
        
        
        if (_gameState == GameStates::eGameOver)
        {
            flash->Show( dt);
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                _data->machine.AddState(StateRef (new GameOverState( _data,_score)),true);
            }
        }
        
        //move dead body with ground
        if (_gameState!=GameStates::eGameOver && (!hitVirus))
        {
            bird->move(dt);
        }
        if (_gameState!=GameStates::eGameOver && hitVirus)
        {
            if (bird->GetDeadBody().getPosition().y<880)
                bird->GetDeadBody().move(- PIPE_MOVEMENT_SPEED * dt, GRAVITY * dt);
            else
                bird->GetDeadBody().move(- PIPE_MOVEMENT_SPEED * dt, 0);
        }
    }

    void GameState::Draw(float dt)
    {
        _data->window.clear();
        background->DrawBackground();
        land->DrawLand();
        bird->Draw();
        flash->Draw();
        hud->Draw();
        virus->Draw_Virus();
        mask->DrawMask();
        sanitizer->DrawSanitizer();
        _data->window.draw(_maskBox);
        maskInventory->Draw();
        _data->window.draw(_sanitizerBox);
        _data->window.display();
        
    }
}

