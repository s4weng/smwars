#include "headers.h"
#include "game.h"
#include "player.h"
#include "AIChar.h"
using namespace std;

sf::RenderWindow Game::mainWindow;
sf::Sprite Game::currentBG;
GameObjectManager Game::GOM;

void Game::start()
{
    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Temp!");

    //player and AI creation
    Player *p = new Player();
    AIChar *a = new AIChar();
    p->setPosition(playerPosX, playerPosY);
    a->setPosition(AICharPosX, AICharPosY);
    GOM.Add("player", p);
    GOM.Add("AI", a);
    sf::Event currentEvent;

    //main game loop
    while (mainWindow.isOpen())
    {
        while (!p->endTurn())
        {
            gameLoop(currentEvent);
            drawPlayer("player");
        }
        while (!a->endTurn())
        {
            gameLoop(currentEvent);
            drawAI();
        }
    }
}

//draws objects (Character characters, ...)
void Game::drawGameObjects()
{
    GOM.updateAll(mainWindow);
    mainWindow.display();
}

void Game::drawPlayer(string player)
{
    GOM.updatePlayer(mainWindow, player);
    mainWindow.display();
}

void Game::drawAI()
{
    GOM.updateAI(mainWindow);
    mainWindow.display();
}

void Game::gameLoop(sf::Event currentEvent)
{
    mainWindow.pollEvent(currentEvent);
    mainWindow.clear(sf::Color(255, 255, 255));

    //if user wants to close window
    if (currentEvent.type == sf::Event::Closed) mainWindow.close();
}