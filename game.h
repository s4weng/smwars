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
    const static int AICharPosX = 500;
    const static int AICharPosY = 600;
private:
	static void gameLoop();
    static void drawGameObjects();
    static void drawPlayer(std::string);
    static void drawAI();

    static sf::RenderWindow mainWindow; 
    static sf::Sprite currentBG; //current game background
    static GameObjectManager GOM;
};


#endif