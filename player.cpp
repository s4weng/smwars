#include "headers.h"
#include "player.h"
#include "game.h"

Player::Player(): velocity(0.0f), maxVelocity(75.0f)
{
    Player::Load("Images/testSprite.jpeg");
    getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
    direction = Right;
}

Player::~Player()
{
}

void Player::Draw(sf::RenderWindow &w)
{
    GameObject::Draw(w);
}

float Player::getVelocity() const
{
    return velocity;
}

void Player::Update(float elapsedTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        velocity -= 25.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        velocity += 25.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        velocity = 0.0f;
    }

    //cap the velocity
    if (abs(velocity) > maxVelocity)
    {
        if (velocity < 0) velocity = -maxVelocity;
        else velocity = maxVelocity;
    }

    sf::Vector2f pos = this->getPosition();

    //if the player collides with the bounds of the screen
    int spriteWidth = getSprite().getLocalBounds().width;
    int pPos = pos.x - spriteWidth / 2;
    if ((pPos  < spriteWidth / 2 && velocity < 0)
            || (pPos > (Game::SCREEN_WIDTH - spriteWidth / 2) && velocity > 0))
    {
        velocity = 0.0f;
    }

    getSprite().move(velocity * elapsedTime, 0);
}