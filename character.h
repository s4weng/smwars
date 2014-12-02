#ifndef _CHARACTER_H__
#define _CHARACTER_H__
#include "GameObject.h"

class Character: public GameObject
{
public:
    Character();
    ~Character();

    void Draw(sf::RenderWindow &);
    float getVelocity() const;

protected:
    int steps;
};

#endif