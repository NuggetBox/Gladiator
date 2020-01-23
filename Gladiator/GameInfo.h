#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "GameObject.h"
#include <cmath>

namespace gameInfo
{
	std::vector<GameObject*> getGameObjects();

	bool getOutOfBounds(Vector2 aPlayerPosition);

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);
}

#endif