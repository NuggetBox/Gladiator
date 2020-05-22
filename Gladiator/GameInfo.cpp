#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;

		float myArenaRadius = 1080 * 0.5f - 50;
		Vector2 myArenaCenter = Vector2(1920.0f * 0.5f, 1080.0f * 0.5f);
	}

	bool getOutOfBounds(Vector2 aNewPosition, float aHitBoxRadius)
	{
		return aNewPosition.Distance(myArenaCenter) + aHitBoxRadius > myArenaRadius;
	}

	Vector2 getArenaCenter()
	{
		return myArenaCenter;
	}

	std::vector<GameObject*>* getGameObjects()
	{
		return myGameObjects;
	}

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects)
	{
		myGameObjects = aPointerToTheGameObjects;
	}

	void addGameObject(GameObject* aGameObject)
	{
		myGameObjects->push_back(aGameObject);
	}
}