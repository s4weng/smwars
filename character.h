#ifndef _CHARACTER_H__
#define _CHARACTER_H__
#include "GameObject.h"

class Character: public GameObject
{
public:
    Character();
    ~Character();

    //void Update(float);
    void Draw(sf::RenderWindow &);

    float getVelocity() const;

protected:
    float velocity, maxVelocity;
};

#endif