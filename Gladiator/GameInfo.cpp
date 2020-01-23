#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;
		float myArenaRadius = 1080 * 0.5f;
		Vector2 myArenaCenter = Vector2(1920.0f * 0.5f, 1080.0f * 0.5f);
	}

	std::vector<GameObject*> getGameObjects()
	{
		return *myGameObjects;
	}

	bool getOutOfBounds(Vector2 aPlayerPosition)
	{
		return (aPlayerPosition - myArenaCenter).Length() > myArenaRadius;
	}

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects)
	{
		myGameObjects = aPointerToTheGameObjects;
	}
}