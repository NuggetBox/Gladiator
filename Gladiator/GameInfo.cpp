#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;

		//Player* myPlayer;
		float myArenaRadius = 1080 * 0.5f - 50;
		Vector2 myArenaCenter = Vector2(1920.0f * 0.5f, 1080.0f * 0.5f);
		bool myBossIsDead = false;
		bool myWinButtonPressed = false;
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

	/*Player* getPlayer()
	{
		return myPlayer;
	}*/

	void setGameObjects(std::vector<GameObject*>* aPointerToTheGameObjects)
	{
		myGameObjects = aPointerToTheGameObjects;
	}

	/*void setPlayer(Player* aPlayerPointer)
	{
		myPlayer = aPlayerPointer;
	}*/

	void addGameObject(GameObject* aGameObject)
	{
		myGameObjects->push_back(aGameObject);
	}

	bool getBossIsDead()
	{
		return myBossIsDead;
	}

	void setBossIsDead(bool anAlive)
	{
		myBossIsDead = anAlive;
	}

	bool getWinButtonPressed()
	{
		return myWinButtonPressed;
	}

	void setWinButton(bool anAlive)
	{
		myWinButtonPressed = anAlive;
	}

	bool* getWinButtonBool()
	{
		return &myWinButtonPressed;
	}
}