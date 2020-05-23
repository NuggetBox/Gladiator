#include "ConditionsInfo.h"

namespace conditionsInfo
{
	namespace
	{
		bool myBossIsDead = false;
		bool myPlayerIsDead = false;
		bool myWinButtonPressed = false;
		bool myLoseButtonPressed = false;
		bool myIronHelmetPressed = false;
		bool myIronArmorPressed = false;
		bool myIronSwordPressed = false;
		bool myDiamondHelmetPressed = false;
		bool myDiamondArmorPressed = false;
		bool myDiamondSwordPressed = false;
		bool myDoneBuying = false;
		bool myFacingChariotFirst = false;
		bool myFacingRetiariusFirst = false;
		bool myVictory = false;
	}


	bool* accessPlayerIsDead() { return &myPlayerIsDead; }

	bool* accessLoseButton() { return &myLoseButtonPressed; }

	bool* accessBossIsDead() { return &myBossIsDead; }

	bool* accessWinButton() { return &myWinButtonPressed; }

	bool* accessIronHelmet() { return &myIronHelmetPressed; }

	bool* accessIronArmor() { return &myIronArmorPressed; }

	bool* accessIronSword() { return &myIronSwordPressed; }

	bool* accessDiamondHelmet() { return &myDiamondHelmetPressed; }

	bool* accessDiamondArmor() { return &myDiamondArmorPressed; }

	bool* accessDiamondSword() { return &myDiamondSwordPressed; }

	bool* accessDoneBuying() { return &myDoneBuying; }

	bool* accessFacingChariotFirst() { return &myFacingChariotFirst; }

	bool* accessFacingRetiariusFirst() { return &myFacingRetiariusFirst; }

	bool* accessVictory() { return &myVictory; }
}