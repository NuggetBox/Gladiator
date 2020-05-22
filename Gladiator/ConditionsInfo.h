#ifndef CONDITIONSINFO_HEADER
#define CONDITIONSINFO_HEADER

namespace conditionsInfo
{
	bool getBossIsDead();
	void setBossIsDead(bool anAlive);

	bool getLoseButtonPressed();
	void setLoseButton(bool anAlive);
	bool* getLoseButtonBool();

	bool getPlayerIsDead();
	void setPlayerIsDead(bool anAlive);

	bool getWinButtonPressed();
	void setWinButton(bool anAlive);
	bool* getWinButtonBool();
}

#endif