
#include "MainMenuState.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include <iostream>
#include "GameState.hpp"

namespace YL
{
    MainMenuState::MainMenuState(GameDataRef data) : _data( data )
    {
    }
    //set every sprite for menu state
    void MainMenuState::Init()
    {
        _data->assets.LoadTexture ("Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
        _data->assets.LoadTexture ("Play Button", PLAY_BUTTON_FILEPATH);
        _data->assets.LoadTexture("About Button", ABOUT_BOTTON_FILEPATH);
        _data->assets.LoadTexture("About Window", ABOUT_WINDOW_FILEPATH);

        _playButton.setTexture(this-> _data->assets.GetTexture("Play Button"));
        _playButton.setPosition((SCREEN_WIDTH/2)-(_playButton.getGlobalBounds().width/2), 550);
        
        _aboutButton.setTexture(_data->assets.GetTexture("About Button"));
        _aboutButton.setPosition((SCREEN_WIDTH/2)-(_aboutButton.getGlobalBounds().width/2), 100);
        _aboutWindow.setTexture(_data->assets.GetTexture("About Window"));
        _aboutWindow.setPosition(2000,2000);
        
        _background.setTexture(_data->assets.GetTexture("Menu Background" ));
        _background2.setTexture(_data->assets.GetTexture("Menu Background" ));
        _background2.setPosition(_background.getGlobalBounds().width  ,0);
    }
    // handlle user click statr
    void MainMenuState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _data-> window.close();
            }
            if (_data->input.IsSpriteClocked(_playButton, sf::Mouse::Left, _data->window))
            {
               _data->machine.AddState(StateRef(new GameState (_data)), true);
            }
            if (_data->input.IsSpriteClocked(_aboutButton, sf::Mouse::Left, _data->window))
            {
                _aboutWindow.setPosition(350, 50);
            }
        }
    }

    void MainMenuState::Update(float dt)
    {
    }

    void MainMenuState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_background2);
        _data->window.draw(_playButton);
        _data->window.draw(_aboutButton);
        _data->window.draw(_aboutWindow);
        _data->window.display();
        
    }
}

