#ifndef STARTINGBOSS_H
#define STARTINGBOSS_H

#define _USE_MATH_DEFINES

#include "Boss.h"
#include "Ray.h"

enum States
{
	Idle,
	Charging,
	Stuck
};

class StartingBoss : public Boss
{

public:
	StartingBoss();
	~StartingBoss();

	void Update(const float& someDelta) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void Attack(const float& someDelta);
	void Idle(const float& someDelta);

private:
	Vector2 myMove;
	int myChargeSpeed;
	float myRotation, myOriginalHealth;
	float myStunTimer, myIdleTimer;
	bool myHasAttacked;
	int myHits;
	States myBossStates;
};

#endif