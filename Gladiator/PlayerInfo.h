#ifndef PLAYERINFO_HEADER
#define PLAEYRINFO_HEADER

#include <vector>
#include "Player.h"

namespace playerInfo
{
	Player* getPlayer();

	void setPlayer(Player* aPointerToPlayer);
}

#endif