#ifndef THIRDBOSS_H
#define THIRDBOSS_H

#include "Boss.h"
#include "Boss3Spear.h"

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

	Boss3Spear* mySpear;

	sf::Texture
		mySpearTexture, myNoSpearTexture, 
		myAimingTexture, myStabTexture;

	int myRegularSpeed, myPickupSpeed;

	float
		myMoveTime, myMoveTimer,
		myAimTime, myAimTimer,
		myPickupTime, myPickupTimer;

	bool myDealtDamage;
};

#endif