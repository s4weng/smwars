#include "headers.h"
#include "GameObjectManager.h"
#include "game.h"

GameObjectManager::GameObjectManager()
{	
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(gameObjects.begin(),gameObjects.end(),GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, GameObject* gameObject)
{
	gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, GameObject*>::iterator results = gameObjects.find(name);
	if(results != gameObjects.end() )
	{
		delete results->second;
		gameObjects.erase(results);
	}
}

GameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, GameObject*>::const_iterator results = gameObjects.find(name);
	if(results == gameObjects.end()) return NULL;
	return results->second;
}

int GameObjectManager::getObjectCount() const
{
	return gameObjects.size();
}


void GameObjectManager::drawAll(sf::RenderWindow& w)
{
	std::map<std::string,GameObject*>::const_iterator itr = gameObjects.begin();
	while(itr != gameObjects.end())
	{
		itr->second->Draw(w);
		itr++;
	}
}

void GameObjectManager::updateAll()
{
  std::map<std::string,GameObject*>::const_iterator itr = gameObjects.begin();
  float timeDelta = clock.restart().asSeconds();

  while(itr != gameObjects.end())
  {
    itr->second->Update(timeDelta);
    itr++;
  }
  
}