#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;

		Player* myPlayer;
		float myArenaRadius = 1080 * 0.5f - 50;
		Vector2 myArenaCenter = Vector2(1920.0f * 0.5f, 1080.0f * 0.5f);
	}

	bool getOutOfBounds(Vector2 aNewPosition, float aHitBoxRadius)
	{
		return aNewPosition.Distance(myArenaCenter) + aHitBoxRadius > myArenaRadius;
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