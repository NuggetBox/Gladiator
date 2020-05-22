#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "GameObject.h"

namespace gameInfo
{
	bool getOutOfBounds(Vector2 aNewPosition, float aHitBoxRadius);

	Vector2 getArenaCenter();

	std::vector<GameObject*>* getGameObjects();

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);

	void addGameObject(GameObject* aGameObject);
}

#endif