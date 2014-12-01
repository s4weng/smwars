#include "headers.h"
#include "game.h"
#include "player.h"
using namespace std;

sf::RenderWindow Game::mainWindow;
sf::Sprite Game::currentBG;
GameObjectManager Game::GOM;

void Game::start()
{
    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Temp!");
    
    //main player
    Player *p = new Player();
    p->setPosition(playerPosX, playerPosY);
    GOM.Add("player", p);

    //main game loop
    while (mainWindow.isOpen())
    {
        gameLoop();
    }
}

//continually update the background...might need a better solution
/*void Game::setBackground()
{
    sf::Texture defaultBG; //draw default background
    if (!defaultBG.loadFromFile("Images/background.jpeg")) cout << "error" << endl;
    currentBG.setTexture(defaultBG);
    mainWindow.draw(currentBG);
}*/

//draws objects (player characters, ...)
void Game::drawGameObjects()
{
    GOM.updateAll();
    GOM.drawAll(mainWindow);
    mainWindow.display();
}

void Game::gameLoop()
{
    sf::Event currentEvent;
    mainWindow.pollEvent(currentEvent);
    mainWindow.clear(sf::Color(255, 255, 255));
    drawGameObjects();

    //if user wants to close window
    if (currentEvent.type == sf::Event::Closed) mainWindow.close();
    mainWindow.display();

}