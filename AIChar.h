#ifndef _AIChar_H__
#define _AIChar_H__
#include "character.h"

class AIChar: public Character
{
public:
    AIChar();
    ~AIChar();

    void Update();

};

#endif