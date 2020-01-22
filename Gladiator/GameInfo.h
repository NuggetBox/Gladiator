#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "GameObject.h"

namespace gameInfo
{
	std::vector<GameObject*> GetGameObjects();

	void SetGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);
}

#endif