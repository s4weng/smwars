#include "headers.h"
#include "character.h"
#include "game.h"

Character::Character(): steps(100), hitpoints(100)
{
    Character::Load("Images/testSprite.jpeg");
    getSprite().setOrigin(getSprite().getLocalBounds().width, getSprite().getLocalBounds().height);
    direction = Right;
}

Character::~Character()
{
}

bool Character::endTurn()
{
    if (steps == 0)
    {
        steps = 100;
        return true;
    }
    else return false;
}

void Character::Draw(sf::RenderWindow &w)
{
    GameObject::Draw(w);
}