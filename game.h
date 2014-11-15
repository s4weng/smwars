#ifndef __GAME_H__
#define __GAME_H__
#include "headers.h"

class Game
{
public:
	static void start();
private:
	static void gameLoop();

	static sf::RenderWindow mainWindow;
};


#endif