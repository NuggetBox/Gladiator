#ifndef GAMEINFO_HEADER
#define GAMEINFO_HEADER

#include <vector>
#include "Player.h"
#include "GameObject.h"	

namespace gameInfo
{
	bool getOutOfBounds(Vector2 aNewPosition, float aHitBoxRadius);

	bool getBossIsDead();

	void setBossIsDead(bool anAlive);

	Vector2 getArenaCenter();

	std::vector<GameObject*>* getGameObjects();

	Player* getPlayer();

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects);

	void setPlayer(Player* aPointerToPlayer);

	void addGameObject(GameObject* aGameObject);
}

#endif