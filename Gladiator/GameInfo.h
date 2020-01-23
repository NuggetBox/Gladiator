#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "Player.h"

namespace gameInfo
{
	std::vector<GameObject*> GetGameObjects();

	std::vector<GameObject*>* GetGameObjectsPointer();

	Player GetPlayer();

	Player* GetPlayerPointer();

	void SetGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);

	void SetPlayer(Player* aPointerToPlayer);
}

#endif