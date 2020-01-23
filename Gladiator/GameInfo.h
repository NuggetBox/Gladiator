#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "Player.h"

namespace gameInfo
{
	std::vector<GameObject*> getGameObjects();

	std::vector<GameObject*>* getGameObjectsPointer();

	Player getPlayer();

	Player* getPlayerPointer();

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);

	void setPlayer(Player* aPointerToPlayer);
}

#endif