#ifndef _PLAYER_H__
#define _PLAYER_H__
#include "GameObject.h"

class Player: public GameObject
{
public:
    Player();
    ~Player();

    void Update(float);
    void Draw(sf::RenderWindow &);

    float getVelocity() const;

private:
    float velocity, maxVelocity;
};

#endif