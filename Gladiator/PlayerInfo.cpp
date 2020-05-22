#include "PlayerInfo.h"

namespace playerInfo
{
	namespace
	{
		Player* myPlayer;
	}

	Player* getPlayer()
	{
		return myPlayer;
	}

	void setPlayer(Player* aPlayerPointer)
	{
		myPlayer = aPlayerPointer;
	}
}