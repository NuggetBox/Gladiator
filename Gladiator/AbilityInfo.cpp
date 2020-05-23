#include "AbilityInfo.h"

namespace abilityInfo
{
	namespace
	{
		int myPlayerHelmetLevel = 1;
		int myPlayerArmorLevel = 1;
		int myPlayerSwordLevel = 1;
	}

	int getPlayerHelmetLevel()
	{
		return myPlayerHelmetLevel;
	}

	void upgradePlayerHelmetLevel()
	{
		myPlayerHelmetLevel++;
	}

	int getPlayerArmorLevel()
	{
		return myPlayerArmorLevel;
	}

	void upgradePlayerArmorLevel()
	{
		myPlayerArmorLevel++;
	}

	int getPlayerSwordLevel()
	{
		return myPlayerSwordLevel;
	}

	void upgradePlayerSwordLevel()
	{
		myPlayerSwordLevel++;
	}
}