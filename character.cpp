#include "headers.h"
#include "character.h"
#include "game.h"

Character::Character(): velocity(0.0f), maxVelocity(75.0f)
{
    Character::Load("Images/testSprite.jpeg");
    getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
    direction = Right;
}

Character::~Character()
{
}

void Character::Draw(sf::RenderWindow &w)
{
    GameObject::Draw(w);
}

float Character::getVelocity() const
{
    return velocity;
}