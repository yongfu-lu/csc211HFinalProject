
#include "Inventory.hpp"
#include <string>

namespace YL
{
    // Text shows how many mask user has on the screen
    Inventory::Inventory(GameDataRef data) : _data(data)
    {
        _maskCountText.setFont( _data ->assets.GetFont( "Flappy Font"));
        _maskCountText.setString("0");
        _maskCountText.setCharacterSize(64);
        _maskCountText.setFillColor(sf::Color::White);
        _maskCountText.setOrigin(_maskCountText.getGlobalBounds().width/2, _maskCountText.getGlobalBounds().height/2);
        _maskCountText.setPosition(250,1070);
        
    }

    void Inventory::Draw()
    {
        _data->window.draw(_maskCountText);
    }

    void Inventory::UpdateInventory(int count)
    {
        _maskCountText.setString( std::to_string( count ));
    }

}
