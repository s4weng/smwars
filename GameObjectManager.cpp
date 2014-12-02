#include "headers.h"
#include "GameObjectManager.h"
#include "game.h"
using namespace std;

GameObjectManager::GameObjectManager()
{	
}

GameObjectManager::~GameObjectManager()
{
	for_each(gameObjects.begin(),gameObjects.end(),GameObjectDeallocator());
}

void GameObjectManager::Add(string name, GameObject* gameObject)
{
	gameObjects.insert(pair<string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(string name)
{
	map<string, GameObject*>::iterator results = gameObjects.find(name);
	if(results != gameObjects.end() )
	{
		delete results->second;
		gameObjects.erase(results);
	}
}

GameObject* GameObjectManager::Get(string name) const
{
	map<string, GameObject*>::const_iterator results = gameObjects.find(name);
	if(results == gameObjects.end()) return NULL;
	return results->second;
}

int GameObjectManager::getObjectCount() const
{
	return gameObjects.size();
}

void GameObjectManager::updateAll(sf::RenderWindow& w)
{
  map<string,GameObject*>::const_iterator itr = gameObjects.begin();
  float timeDelta = clock.restart().asSeconds();

  while(itr != gameObjects.end())
  {
    itr->second->Update(timeDelta);
    itr->second->Draw(w);
    itr++;
  }
  
}