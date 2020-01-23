#include "GameInfo.h"

namespace gameInfo
{
	namespace
	{
		std::vector<GameObject*>* myGameObjects;
	}

	std::vector<GameObject*> GetGameObjects()
	{
		return *myGameObjects;
	}

	void SetGameObjects(std::vector<GameObject*>*)
	{

	}
}