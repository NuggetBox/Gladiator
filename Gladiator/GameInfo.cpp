#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;

		Player* myPlayer;
	}

	std::vector<GameObject*> getGameObjects()
	{
		return *myGameObjects;
	}

	std::vector<GameObject*>* getGameObjectsPointer()
	{
		return myGameObjects;
	}

	Player getPlayer()
	{
		return *myPlayer;
	}

	Player* getPlayerPointer()
	{
		return myPlayer;
	}

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects)
	{
		myGameObjects = aPointerToTheGameObjects;
	}

	void setPlayer(Player* aPlayerPointer)
	{
		myPlayer = aPlayerPointer;
	}
}