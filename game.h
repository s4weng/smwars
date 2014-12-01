#ifndef __GAME_H__
#define __GAME_H__
#include "headers.h"
#include "GameObjectManager.h"

class Game
{
public:
	static void start();
	
	const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;
    const static int playerPosX = 300;
    const static int playerPosY = 600;
private:
	static void gameLoop();
    //static void setBackground();
    static void drawGameObjects();

    static sf::RenderWindow mainWindow; 
    static sf::Sprite currentBG; //current game background
    static GameObjectManager GOM;
};


#endif