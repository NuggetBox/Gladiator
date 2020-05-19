#ifndef THIRDBOSS_H
#define THIRDBOSS_H

#include "Boss.h"
#include "Spear.h"

enum ThirdBossStates
{
	Moving, Aiming, Pickup
};

class ThirdBoss : public Boss
{
public:
	ThirdBoss();
	~ThirdBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;
	void ThrowSpear();

private:
	ThirdBossStates myState;

	Spear* mySpear;

	sf::Texture mySpearTexture, myNoSpearTexture, myAimingTexture;

	float
		myMoveTime, myMoveTimer,
		myAimTime, myAimTimer,
		myPickupTime, myPickupTimer;
};

#endif