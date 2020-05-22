#include "ConditionsInfo.h"

namespace conditionsInfo
{
	namespace
	{
		bool myBossIsDead = false;
		bool myPlayerIsDead = false;
		bool myWinButtonPressed = false;
		bool myLoseButtonPressed = false;
	}


	bool getPlayerIsDead()
	{
		return myPlayerIsDead;
	}

	void setPlayerIsDead(bool anAlive)
	{
		myPlayerIsDead = anAlive;
	}


	bool getLoseButtonPressed()
	{
		return myLoseButtonPressed;
	}

	void setLoseButton(bool anAlive)
	{
		myLoseButtonPressed = anAlive;
	}

	bool* getLoseButtonBool()
	{
		return &myLoseButtonPressed;
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