#include "headers.h"
#include "player.h"
#include "game.h"

Player::Player() {}

Player::~Player() {}

void Player::Update(float elapsedTime)
{
    //find the current position of the character
    sf::Vector2f pos = this->getPosition();
    int spriteWidth = getSprite().getLocalBounds().width;
    int pPos = pos.x - spriteWidth / 2;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //if the sprite won't move out of bounds
        if (pPos > spriteWidth / 2 && steps > 0)
        {
            getSprite().move(-5, 0);
            --steps;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (pPos < (Game::SCREEN_WIDTH - spriteWidth / 2) && steps > 0)
        {
            getSprite().move(5, 0);
            --steps;
        }
    }
}