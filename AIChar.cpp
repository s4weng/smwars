#include "headers.h"
#include "AIChar.h"
#include "game.h"

AIChar::AIChar() {}

AIChar::~AIChar() {}

//temporary testing code
void AIChar::Update()
{
    sf::Vector2f pos = this->getPosition();
    int spriteWidth = getSprite().getLocalBounds().width;
    int pPos = pos.x - spriteWidth / 2;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        //if the sprite won't move out of bounds
        if (pPos > spriteWidth / 2 && steps > 0)
        {
            getSprite().move(-5, 0);
            --steps;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (pPos < (Game::SCREEN_WIDTH - spriteWidth / 2) && steps > 0)
        {
            getSprite().move(5, 0);
            --steps;
        }
    }
}