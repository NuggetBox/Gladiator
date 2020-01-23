#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;

		Player* myPlayer;
	}

	std::vector<GameObject*> GetGameObjects()
	{
		return *myGameObjects;
	}

	std::vector<GameObject*>* GetGameObjectsPointer()
	{
		return myGameObjects;
	}

	Player GetPlayer()
	{
		return *myPlayer;
	}

	Player* GetPlayerPointer()
	{
		return myPlayer;
	}

	void SetGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects)
	{
		myGameObjects = aPointerToTheGameObjects;
	}

	void SetPlayer(Player* aPlayerPointer)
	{
		myPlayer = aPlayerPointer;
	}
}