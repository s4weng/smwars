#include "game.h"

sf::RenderWindow Game::mainWindow;

void Game::start()
{
    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Temp!");
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