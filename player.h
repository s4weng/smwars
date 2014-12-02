#ifndef _PLAYER_H__
#define _PLAYER_H__
#include "character.h"

class Player: public Character
{
public:
    Player();
    ~Player();

    void Update(float);
};

#endif