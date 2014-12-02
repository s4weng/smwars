#ifndef _GAMEOBJECTMANAGER_H__
#define _GAMEOBJECTMANAGER_H__

#include "GameObject.h"

class GameObjectManager
{
	public:
		GameObjectManager();
		~GameObjectManager();

		void Add(std::string name, GameObject*);
		void Remove(std::string);
		int getObjectCount() const;
		GameObject* Get(std::string) const;
		void updateAll(sf::RenderWindow &);

	private:
		std::map<std::string, GameObject*> gameObjects;
		sf::Clock clock;
		struct GameObjectDeallocator
		{
			void operator()(const std::pair<std::string, GameObject*> &p) const
			{
				delete p.second;
			}
		};
};

#endif