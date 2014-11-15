#include "headers.h"
#include "game.h"
using namespace std;

sf::RenderWindow Game::mainWindow;

void Game::start()
{
    mainWindow.create(sf::VideoMode(1024, 768, 32), "Temp!");
    while (mainWindow.isOpen())
    {
        gameLoop();
    }
}


void Game::gameLoop()
{
    sf::Event currentEvent;

    mainWindow.pollEvent(currentEvent);
    if (currentEvent.type == sf::Event::Closed)
        mainWindow.close();

}