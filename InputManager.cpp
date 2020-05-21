
#include "InputManager.hpp"
namespace YL
{
    // this function is for check mouse click in the future
    bool InputManager::IsSpriteClocked (sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect temRect( object.getPosition().x, object.getPosition().y,object.getGlobalBounds().width,object.getGlobalBounds().height);
            
            if (temRect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }
        return false;
    }
           
    sf::Vector2i InputManager::GetMousePosition (sf::RenderWindow & window)
    {
        return sf::Mouse::getPosition(window);
    }
}
